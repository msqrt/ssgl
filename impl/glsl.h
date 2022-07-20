#pragma once

namespace glsl {

    template<typename... I>
    constexpr int maximal(I... i) {
        int max = 0;
        ((max = max < i ? i : max), ...);
        return max;
    }

    template<int... I> struct sequence { using type = sequence; };

    template<typename I1, typename I2> struct append;
    template<int... I1, int... I2>
    struct append<sequence<I1...>, sequence<I2...>> :
        sequence<I1..., (sizeof...(I1) + I2)...> {};

    template<int N>
    struct iota : append<typename iota<N / 2>::type, typename iota<N - N / 2>::type> {};
    template<> struct iota<0> : sequence<> {};
    template<> struct iota<1> : sequence<0> {};

    template<int R, int C, typename F, int... I> struct Matrix;

    template<int R, int C, typename F, int... I>
    auto id_ptr(sequence<I...>) {
        if constexpr (R == 1 && C == 1) return (F*) nullptr;
        else return (Matrix<R, C, F, I...>*) nullptr;
    }

    template<typename F> struct no_ptr_ { using type = F; };
    template<typename F> struct no_ptr_<F*> { using type = F; };
    template<typename F> struct no_ptr_<const F*> { using type = const F; };
    template<typename F> using no_ptr = typename no_ptr_<F>::type;

    template<int R, int C, typename F>
    using identity = no_ptr<decltype(id_ptr<R, C, F>(iota<R* C>{})) > ;

    template<typename F> struct no_const_ { using type = F; };
    template<typename F> struct no_const_<const F> { using type = F; };
    template<typename F> struct no_const_<const F*> { using type = F*; };
    template<typename F> using no_const = typename no_const_<F>::type;

    template<typename F> constexpr bool is_const = false;
    template<typename F> constexpr bool is_const<const F> = true;

    template<typename T> constexpr int Rows = 1;
    template<int R, int C, typename F, int... I>
    constexpr int Rows<Matrix<R, C, F, I...>> = R;

    template<typename T> constexpr int Columns = 1;
    template<int R, int C, typename F, int... I>
    constexpr int Columns<Matrix<R, C, F, I...>> = C;

    template<typename T> struct Field_ { using type = T; };
    template<int R, int C, typename F, int... I>
    struct Field_<Matrix<R, C, F, I...>> { using type = no_ptr<F>; };

    template<typename T>
    using Field = typename Field_<T>::type;

    template<bool>
    struct enabler {};
    template<>
    struct enabler<true> { using type = bool; };
    template<bool b>
    using enable = typename enabler<b>::type;

    template<typename T, typename U>
    constexpr bool same = false;
    template<typename T>
    constexpr bool same<T, T> = true;


    template<typename... Args>
    constexpr bool broadcastable = ((Rows<Args> == maximal(Rows<Args>...) && Columns<Args> == maximal(Columns<Args>...) || Rows<Args> == 1 && Columns<Args> == 1)&&...);
    template<typename First, typename Second>
    constexpr bool matmul_broadcastable = Columns<First> == 1 && Rows<First> == Rows<Second> || Columns<First> == Rows<Second> || broadcastable<First, Second>;

    template<typename... Args, int... I>
    auto broadcast_type(sequence<I...>) {
        constexpr int rows = maximal(Rows<Args>...), columns = maximal(Columns<Args>...);
        auto sum = (Field<Args>{} + ...);
        if constexpr (rows == 1 && columns == 1)
            return sum;
        else
            return Matrix<rows, columns, const decltype(sum), I...> {};
    }

    template<typename... Args>
    using Iota = iota<maximal(Rows<Args>...)* maximal(Columns<Args>...)>;
    template<typename... Args>
    using Common = decltype(broadcast_type<Args...>(Iota<Args...>{}));

    template<typename First, typename Second, int... I>
    auto matmul_type(sequence<I...>) {
        auto sum = Field<First>{} + Field<Second>{};
        if constexpr (Columns<First> == 1 && Columns<Second> == 1)
            return Matrix<maximal(Rows<First>, Rows<Second>), 1, const decltype(sum), I...> {};
        else if constexpr (Columns<First> == 1)
            return Matrix<Columns<Second>, 1, const decltype(sum), I...> {};
        else if constexpr (Rows<First> == 1 && Columns<First> == 1) return Second{};
        else if constexpr (Rows<Second> == 1 && Columns<Second> == 1) return First{};
        else
            return Matrix<Rows<First>, Columns<Second>, const decltype(sum), I...> {};
    }

    template<typename First, typename Second>
    constexpr int mult_iota_length() {
        if constexpr (Columns<First> == 1 && Columns<Second> == 1) return maximal(Rows<First>, Rows<Second>);
        else return ((Columns<First> == 1) ? 1 : Rows<First>) * Columns<Second>;
    }

    template<typename First, typename Second>
    using MultCommon = decltype(matmul_type<First, Second>(iota<mult_iota_length<First, Second>()>{}));

    template<int... I, int... Id>
    constexpr int ordering(sequence<Id...>) {
        return int(((int(I) * (int(1) << int((sizeof...(I) - Id) * 4))) + ... + 0));
    }

    template<int R, int C, typename F, int... I>
    struct Container {
        Container() = default;
        no_ptr<no_const<F>> data[1 + maximal(I...)];
    };

    template<int R, int C, typename F, int... I>
    struct Matrix : Container<R, C, no_const<F>, I...> {

        using Container<R, C, no_const<F>, I...>::data;

        static_assert(sizeof...(I) == R * C);
        //static_assert(R* C > 1);

        Matrix() = default;

        explicit Matrix(const F& f) {
            if constexpr (C == 1 || is_const<F>) ((data[I] = f), ...);
            else {
                F choice[2] = { F(0), f };
                ((data[I] = choice[I % R == I / R]), ...);
            }
        }
        template<int R2, int C2, typename F2, int... I2, typename = enable<(R == R2 && C == C2) || (C > 1 && C2 > 1) || (R2==1 && C2==1)> >
        explicit Matrix(const Matrix<R2, C2, F2, I2...>& other) {
            if constexpr (R2 == 1 && C2 == 1) {
                constexpr int i2[] = { I2... };
                const auto f = F(other.data[i2[0]]);
                if constexpr (C == 1 || is_const<F>) ((data[I] = f), ...);
                else {
                    F choice[2] = { F(0),  f };
                    ((data[I] = choice[I % R == I / R]), ...);
                }
            }
            else if constexpr (R == R2 && C == C2) {
                int i2[] = { I2... };
                ((data[I] = F(other.data[i2[I]])), ...);
            }
            else {
                F choice[2] = { 0, 1 };
                // I%R gives the row and I/R the column
                ((data[I] = (I % R < R2&& I / R < C2) ? F(other.data[((I / R) * R2) + (I % R)]) : choice[I % R == I / R]), ...);
            }
        }

        template<int R2, typename F2, int... I2>
        void place(const Matrix<R2, 1, F2, I2...>& m, int& i) {
            ((data[i++] = F(m.data[I2])), ...);
        }
        template<typename F2>
        void place(const F2& m, int& i) {
            data[i++] = F(m);
        }
        template<typename First, typename Second, typename... Rest, typename = enable<Columns<First> == 1 && Columns<Second> == 1 && ((Columns<Rest> == 1) && ...) && R * C == ((Rows<First> +Rows<Second>) + ... + Rows<Rest>)>>
        Matrix(const First& first, const Second& second, const Rest&... rest) {
            int i = 0;
            place(first, i); place(second, i); (place(rest, i), ...);
        }

        template<typename F2, typename = enable<!same<F2*, const F2*>>>
        operator Matrix<R, C, F2, I...>() const {
            Matrix<R, C, F2, I...> result;
            ((result.data[I] = no_ptr<F2>(data[I])), ...);
            return result;
        }

        template<typename F2, int... I2>
        auto& operator=(const Matrix<R, C, F2, I2...> other) {
            ((data[I] = F(other.data[I2])), ...);
            return *this;
        }
        auto& operator=(const Matrix& other) {
            ((data[I] = other.data[I]), ...);
            return *this;
        }

        static constexpr int inds[] = { I... };
        auto& operator[](int i) {
            if constexpr (C == 1) return data[inds[i]];
            else return *reinterpret_cast<identity<R, 1, F>*>(data + i * R);
        }
        const auto& operator[](int i) const {
            if constexpr (C == 1) return const_cast<F&>(data[inds[i]]);
            else return *reinterpret_cast<const identity<R, 1, F>*const>(data + i * R);
        }

        auto& operator+=(const identity<R, C, F>& other) {return *this = *this + other;}
        auto& operator-=(const identity<R, C, F>& other) {return *this = *this - other;}
        auto& operator/=(const identity<R, C, F>& other) {return *this = *this / other;}
        auto& operator+=(const F& other) { return *this = *this + other; }
        auto& operator-=(const F& other) { return *this = *this - other; }
        auto& operator/=(const F& other) { return *this = *this / other; }
        template<typename Other>
        auto& operator*=(const Other& other) { return *this = *this * other; }
    };

    template<int R, typename F, int... I>
    struct Matrix<R, 1, F*, I...> {

        no_const<F> data[1 + maximal(I...)];

        template<typename F2, int... I2, typename = enable < (same < F2*, const F* > || same < const decltype(F{} + no_ptr<F2>{}), const F > ) && (ordering<I...>(iota<sizeof...(I)>{}) >= ordering<I2...>(iota<sizeof...(I2)>{})) >>
            operator Matrix<R, 1, F2, I2...>() const {
            Matrix<R, 1, F2, I2...>result;
            ((result.data[I2] = no_ptr<F2>(data[I])), ...);
            return result;
        }

        template<typename F2, int... I2>
        auto& operator=(const Matrix<R, 1, F2, I2...> other) {
            ((data[I] = F(other.data[I2])), ...);
            return *this;
        }
        auto& operator=(const Matrix& other) {
            ((data[I] = other.data[I]), ...);
            return *this;
        }

        auto& operator+=(const identity<R, 1, F>& other) { return *this = *this + other; }
        auto& operator-=(const identity<R, 1, F>& other) { return *this = *this - other; }
        auto& operator/=(const identity<R, 1, F>& other) { return *this = *this / other; }
        auto& operator+=(const F& other) { return *this = *this + other; }
        auto& operator-=(const F& other) { return *this = *this - other; }
        auto& operator/=(const F& other) { return *this = *this / other; }
        template<typename Other>
        auto& operator*=(const Other& other) { return *this = *this * other; }
    };

    template<int R, typename F, int... I>
    struct Matrix<R, 1, const F*, I...> {

        F data[1 + maximal(I...)];

        template<typename F2, int... I2, typename = enable < (same < F2*, const F* > || same < const decltype(F{} + no_ptr<F2>{}), const F > ) && (ordering<I...>(iota<sizeof...(I)>{}) >= ordering<I2...>(iota<sizeof...(I2)>{})) >>
            operator Matrix<R, 1, F2, I2...>() const {
            Matrix<R, 1, F2, I2...> result;
            ((result.data[I2] = no_ptr<F2>(data[I])), ...);
            return result;
        }
        template<int... I2>
        operator Matrix<R, 1, no_ptr<F>, I2...>() const {
            Matrix<R, 1, no_ptr<F>, I2...> result;
            ((result.data[I2] = no_ptr<F>(data[I])), ...);
            return result;
        }
    };

    template<typename F, int I>
    struct Matrix<1, 1, F*, I> {

        no_const<F> data[1 + I];
        auto* operator&() {
            return &data[I];
        }
        auto& operator=(const F& other) {
            data[I] = other;
            return *this;
        }
        operator F& () { return data[I]; }
        operator F() const { return data[I]; }
    };

    template<typename F, int I>
    struct Matrix<1, 1, const F*, I> {
        F data[1 + I];
        operator F() const { return data[I]; }
    };


    template<typename F>
    struct Container<2, 1, F, 0, 1> {
        Container() = default;
        union {
            no_ptr<no_const<F>> data[2];

            Matrix<1, 1, no_ptr<F>*, 0> x, r, s;
            Matrix<1, 1, no_ptr<F>*, 1> y, g, t;

            Matrix<2, 1, const no_ptr<F>*, 0, 0> xx, rr, ss;
            Matrix<2, 1, no_ptr<F>*, 0, 1> xy, rg, st;
            Matrix<2, 1, no_ptr<F>*, 1, 0> yx, gr, ts;
            Matrix<2, 1, const no_ptr<F>*, 1, 1> yy, gg, tt;

            Matrix<3, 1, const no_ptr<F>*, 0, 0, 0> xxx, rrr, sss;
            Matrix<3, 1, const no_ptr<F>*, 0, 0, 1> xxy, rrg, sst;
            Matrix<3, 1, const no_ptr<F>*, 0, 1, 0> xyx, rgr, sts;
            Matrix<3, 1, const no_ptr<F>*, 0, 1, 1> xyy, rgg, stt;
            Matrix<3, 1, const no_ptr<F>*, 1, 0, 0> yxx, grr, tss;
            Matrix<3, 1, const no_ptr<F>*, 1, 0, 1> yxy, grg, tst;
            Matrix<3, 1, const no_ptr<F>*, 1, 1, 0> yyx, ggr, tts;
            Matrix<3, 1, const no_ptr<F>*, 1, 1, 1> yyy, ggg, ttt;

            Matrix<4, 1, const no_ptr<F>*, 0, 0, 0, 0> xxxx, rrrr, ssss;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 0, 1> xxxy, rrrg, ssst;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 1, 0> xxyx, rrgr, ssts;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 1, 1> xxyy, rrgg, sstt;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 0, 0> xyxx, rgrr, stss;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 0, 1> xyxy, rgrg, stst;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 1, 0> xyyx, rggr, stts;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 1, 1> xyyy, rggg, sttt;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 0, 0> yxxx, grrr, tsss;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 0, 1> yxxy, grrg, tsst;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 1, 0> yxyx, grgr, tsts;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 1, 1> yxyy, grgg, tstt;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 0, 0> yyxx, ggrr, ttss;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 0, 1> yyxy, ggrg, ttst;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 1, 0> yyyx, gggr, ttts;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 1, 1> yyyy, gggg, tttt;
        };
    };

    template<typename F>
    struct Container<3, 1, F, 0, 1, 2> {
        Container() = default;
        union {
            no_ptr<no_const<F>> data[3];

            Matrix<1, 1, no_ptr<F>*, 0> x, r, s;
            Matrix<1, 1, no_ptr<F>*, 1> y, g, t;
            Matrix<1, 1, no_ptr<F>*, 2> z, b, p;

            Matrix<2, 1, const no_ptr<F>*, 0, 0> xx, rr, ss;
            Matrix<2, 1, no_ptr<F>*, 0, 1> xy, rg, st;
            Matrix<2, 1, no_ptr<F>*, 0, 2> xz, rb, sp;
            Matrix<2, 1, no_ptr<F>*, 1, 0> yx, gr, ts;
            Matrix<2, 1, const no_ptr<F>*, 1, 1> yy, gg, tt;
            Matrix<2, 1, no_ptr<F>*, 1, 2> yz, gb, tp;
            Matrix<2, 1, no_ptr<F>*, 2, 0> zx, br, ps;
            Matrix<2, 1, no_ptr<F>*, 2, 1> zy, bg, pt;
            Matrix<2, 1, const no_ptr<F>*, 2, 2> zz, bb, pp;

            Matrix<3, 1, const no_ptr<F>*, 0, 0, 0> xxx, rrr, sss;
            Matrix<3, 1, const no_ptr<F>*, 0, 0, 1> xxy, rrg, sst;
            Matrix<3, 1, const no_ptr<F>*, 0, 0, 2> xxz, rrb, ssp;
            Matrix<3, 1, const no_ptr<F>*, 0, 1, 0> xyx, rgr, sts;
            Matrix<3, 1, const no_ptr<F>*, 0, 1, 1> xyy, rgg, stt;
            Matrix<3, 1, no_ptr<F>*, 0, 1, 2> xyz, rgb, stp;
            Matrix<3, 1, const no_ptr<F>*, 0, 2, 0> xzx, rbr, sps;
            Matrix<3, 1, no_ptr<F>*, 0, 2, 1> xzy, rbg, spt;
            Matrix<3, 1, const no_ptr<F>*, 0, 2, 2> xzz, rbb, spp;
            Matrix<3, 1, const no_ptr<F>*, 1, 0, 0> yxx, grr, tss;
            Matrix<3, 1, const no_ptr<F>*, 1, 0, 1> yxy, grg, tst;
            Matrix<3, 1, no_ptr<F>*, 1, 0, 2> yxz, grb, tsp;
            Matrix<3, 1, const no_ptr<F>*, 1, 1, 0> yyx, ggr, tts;
            Matrix<3, 1, const no_ptr<F>*, 1, 1, 1> yyy, ggg, ttt;
            Matrix<3, 1, const no_ptr<F>*, 1, 1, 2> yyz, ggb, ttp;
            Matrix<3, 1, no_ptr<F>*, 1, 2, 0> yzx, gbr, tps;
            Matrix<3, 1, const no_ptr<F>*, 1, 2, 1> yzy, gbg, tpt;
            Matrix<3, 1, const no_ptr<F>*, 1, 2, 2> yzz, gbb, tpp;
            Matrix<3, 1, const no_ptr<F>*, 2, 0, 0> zxx, brr, pss;
            Matrix<3, 1, no_ptr<F>*, 2, 0, 1> zxy, brg, pst;
            Matrix<3, 1, const no_ptr<F>*, 2, 0, 2> zxz, brb, psp;
            Matrix<3, 1, no_ptr<F>*, 2, 1, 0> zyx, bgr, pts;
            Matrix<3, 1, const no_ptr<F>*, 2, 1, 1> zyy, bgg, ptt;
            Matrix<3, 1, const no_ptr<F>*, 2, 1, 2> zyz, bgb, ptp;
            Matrix<3, 1, const no_ptr<F>*, 2, 2, 0> zzx, bbr, pps;
            Matrix<3, 1, const no_ptr<F>*, 2, 2, 1> zzy, bbg, ppt;
            Matrix<3, 1, const no_ptr<F>*, 2, 2, 2> zzz, bbb, ppp;

            Matrix<4, 1, const no_ptr<F>*, 0, 0, 0, 0> xxxx, rrrr, ssss;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 0, 1> xxxy, rrrg, ssst;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 0, 2> xxxz, rrrb, sssp;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 1, 0> xxyx, rrgr, ssts;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 1, 1> xxyy, rrgg, sstt;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 1, 2> xxyz, rrgb, sstp;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 2, 0> xxzx, rrbr, ssps;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 2, 1> xxzy, rrbg, sspt;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 2, 2> xxzz, rrbb, sspp;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 0, 0> xyxx, rgrr, stss;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 0, 1> xyxy, rgrg, stst;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 0, 2> xyxz, rgrb, stsp;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 1, 0> xyyx, rggr, stts;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 1, 1> xyyy, rggg, sttt;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 1, 2> xyyz, rggb, sttp;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 2, 0> xyzx, rgbr, stps;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 2, 1> xyzy, rgbg, stpt;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 2, 2> xyzz, rgbb, stpp;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 0, 0> xzxx, rbrr, spss;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 0, 1> xzxy, rbrg, spst;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 0, 2> xzxz, rbrb, spsp;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 1, 0> xzyx, rbgr, spts;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 1, 1> xzyy, rbgg, sptt;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 1, 2> xzyz, rbgb, sptp;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 2, 0> xzzx, rbbr, spps;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 2, 1> xzzy, rbbg, sppt;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 2, 2> xzzz, rbbb, sppp;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 0, 0> yxxx, grrr, tsss;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 0, 1> yxxy, grrg, tsst;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 0, 2> yxxz, grrb, tssp;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 1, 0> yxyx, grgr, tsts;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 1, 1> yxyy, grgg, tstt;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 1, 2> yxyz, grgb, tstp;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 2, 0> yxzx, grbr, tsps;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 2, 1> yxzy, grbg, tspt;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 2, 2> yxzz, grbb, tspp;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 0, 0> yyxx, ggrr, ttss;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 0, 1> yyxy, ggrg, ttst;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 0, 2> yyxz, ggrb, ttsp;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 1, 0> yyyx, gggr, ttts;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 1, 1> yyyy, gggg, tttt;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 1, 2> yyyz, gggb, tttp;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 2, 0> yyzx, ggbr, ttps;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 2, 1> yyzy, ggbg, ttpt;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 2, 2> yyzz, ggbb, ttpp;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 0, 0> yzxx, gbrr, tpss;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 0, 1> yzxy, gbrg, tpst;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 0, 2> yzxz, gbrb, tpsp;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 1, 0> yzyx, gbgr, tpts;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 1, 1> yzyy, gbgg, tptt;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 1, 2> yzyz, gbgb, tptp;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 2, 0> yzzx, gbbr, tpps;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 2, 1> yzzy, gbbg, tppt;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 2, 2> yzzz, gbbb, tppp;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 0, 0> zxxx, brrr, psss;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 0, 1> zxxy, brrg, psst;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 0, 2> zxxz, brrb, pssp;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 1, 0> zxyx, brgr, psts;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 1, 1> zxyy, brgg, pstt;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 1, 2> zxyz, brgb, pstp;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 2, 0> zxzx, brbr, psps;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 2, 1> zxzy, brbg, pspt;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 2, 2> zxzz, brbb, pspp;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 0, 0> zyxx, bgrr, ptss;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 0, 1> zyxy, bgrg, ptst;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 0, 2> zyxz, bgrb, ptsp;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 1, 0> zyyx, bggr, ptts;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 1, 1> zyyy, bggg, pttt;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 1, 2> zyyz, bggb, pttp;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 2, 0> zyzx, bgbr, ptps;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 2, 1> zyzy, bgbg, ptpt;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 2, 2> zyzz, bgbb, ptpp;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 0, 0> zzxx, bbrr, ppss;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 0, 1> zzxy, bbrg, ppst;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 0, 2> zzxz, bbrb, ppsp;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 1, 0> zzyx, bbgr, ppts;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 1, 1> zzyy, bbgg, pptt;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 1, 2> zzyz, bbgb, pptp;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 2, 0> zzzx, bbbr, ppps;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 2, 1> zzzy, bbbg, pppt;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 2, 2> zzzz, bbbb, pppp;
        };
    };
    template<typename F>
    struct Container<4, 1, F, 0, 1, 2, 3> {
        Container() = default;
        union {
            no_ptr<no_const<F>> data[4];

            Matrix<1, 1, no_ptr<F>*, 0> x, r, s;
            Matrix<1, 1, no_ptr<F>*, 1> y, g, t;
            Matrix<1, 1, no_ptr<F>*, 2> z, b, p;
            Matrix<1, 1, no_ptr<F>*, 3> w, a, q;

            Matrix<2, 1, const no_ptr<F>*, 0, 0> xx, rr, ss;
            Matrix<2, 1, no_ptr<F>*, 0, 1> xy, rg, st;
            Matrix<2, 1, no_ptr<F>*, 0, 2> xz, rb, sp;
            Matrix<2, 1, no_ptr<F>*, 0, 3> xw, ra, sq;
            Matrix<2, 1, no_ptr<F>*, 1, 0> yx, gr, ts;
            Matrix<2, 1, const no_ptr<F>*, 1, 1> yy, gg, tt;
            Matrix<2, 1, no_ptr<F>*, 1, 2> yz, gb, tp;
            Matrix<2, 1, no_ptr<F>*, 1, 3> yw, ga, tq;
            Matrix<2, 1, no_ptr<F>*, 2, 0> zx, br, ps;
            Matrix<2, 1, no_ptr<F>*, 2, 1> zy, bg, pt;
            Matrix<2, 1, const no_ptr<F>*, 2, 2> zz, bb, pp;
            Matrix<2, 1, no_ptr<F>*, 2, 3> zw, ba, pq;
            Matrix<2, 1, no_ptr<F>*, 3, 0> wx, ar, qs;
            Matrix<2, 1, no_ptr<F>*, 3, 1> wy, ag, qt;
            Matrix<2, 1, no_ptr<F>*, 3, 2> wz, ab, qp;
            Matrix<2, 1, const no_ptr<F>*, 3, 3> ww, aa, qq;

            Matrix<3, 1, const no_ptr<F>*, 0, 0, 0> xxx, rrr, sss;
            Matrix<3, 1, const no_ptr<F>*, 0, 0, 1> xxy, rrg, sst;
            Matrix<3, 1, const no_ptr<F>*, 0, 0, 2> xxz, rrb, ssp;
            Matrix<3, 1, const no_ptr<F>*, 0, 0, 3> xxw, rra, ssq;
            Matrix<3, 1, const no_ptr<F>*, 0, 1, 0> xyx, rgr, sts;
            Matrix<3, 1, const no_ptr<F>*, 0, 1, 1> xyy, rgg, stt;
            Matrix<3, 1, no_ptr<F>*, 0, 1, 2> xyz, rgb, stp;
            Matrix<3, 1, no_ptr<F>*, 0, 1, 3> xyw, rga, stq;
            Matrix<3, 1, const no_ptr<F>*, 0, 2, 0> xzx, rbr, sps;
            Matrix<3, 1, no_ptr<F>*, 0, 2, 1> xzy, rbg, spt;
            Matrix<3, 1, const no_ptr<F>*, 0, 2, 2> xzz, rbb, spp;
            Matrix<3, 1, no_ptr<F>*, 0, 2, 3> xzw, rba, spq;
            Matrix<3, 1, const no_ptr<F>*, 0, 3, 0> xwx, rar, sqs;
            Matrix<3, 1, no_ptr<F>*, 0, 3, 1> xwy, rag, sqt;
            Matrix<3, 1, no_ptr<F>*, 0, 3, 2> xwz, rab, sqp;
            Matrix<3, 1, const no_ptr<F>*, 0, 3, 3> xww, raa, sqq;
            Matrix<3, 1, const no_ptr<F>*, 1, 0, 0> yxx, grr, tss;
            Matrix<3, 1, const no_ptr<F>*, 1, 0, 1> yxy, grg, tst;
            Matrix<3, 1, no_ptr<F>*, 1, 0, 2> yxz, grb, tsp;
            Matrix<3, 1, no_ptr<F>*, 1, 0, 3> yxw, gra, tsq;
            Matrix<3, 1, const no_ptr<F>*, 1, 1, 0> yyx, ggr, tts;
            Matrix<3, 1, const no_ptr<F>*, 1, 1, 1> yyy, ggg, ttt;
            Matrix<3, 1, const no_ptr<F>*, 1, 1, 2> yyz, ggb, ttp;
            Matrix<3, 1, const no_ptr<F>*, 1, 1, 3> yyw, gga, ttq;
            Matrix<3, 1, no_ptr<F>*, 1, 2, 0> yzx, gbr, tps;
            Matrix<3, 1, const no_ptr<F>*, 1, 2, 1> yzy, gbg, tpt;
            Matrix<3, 1, const no_ptr<F>*, 1, 2, 2> yzz, gbb, tpp;
            Matrix<3, 1, no_ptr<F>*, 1, 2, 3> yzw, gba, tpq;
            Matrix<3, 1, no_ptr<F>*, 1, 3, 0> ywx, gar, tqs;
            Matrix<3, 1, const no_ptr<F>*, 1, 3, 1> ywy, gag, tqt;
            Matrix<3, 1, no_ptr<F>*, 1, 3, 2> ywz, gab, tqp;
            Matrix<3, 1, const no_ptr<F>*, 1, 3, 3> yww, gaa, tqq;
            Matrix<3, 1, const no_ptr<F>*, 2, 0, 0> zxx, brr, pss;
            Matrix<3, 1, no_ptr<F>*, 2, 0, 1> zxy, brg, pst;
            Matrix<3, 1, const no_ptr<F>*, 2, 0, 2> zxz, brb, psp;
            Matrix<3, 1, no_ptr<F>*, 2, 0, 3> zxw, bra, psq;
            Matrix<3, 1, no_ptr<F>*, 2, 1, 0> zyx, bgr, pts;
            Matrix<3, 1, const no_ptr<F>*, 2, 1, 1> zyy, bgg, ptt;
            Matrix<3, 1, const no_ptr<F>*, 2, 1, 2> zyz, bgb, ptp;
            Matrix<3, 1, no_ptr<F>*, 2, 1, 3> zyw, bga, ptq;
            Matrix<3, 1, const no_ptr<F>*, 2, 2, 0> zzx, bbr, pps;
            Matrix<3, 1, const no_ptr<F>*, 2, 2, 1> zzy, bbg, ppt;
            Matrix<3, 1, const no_ptr<F>*, 2, 2, 2> zzz, bbb, ppp;
            Matrix<3, 1, const no_ptr<F>*, 2, 2, 3> zzw, bba, ppq;
            Matrix<3, 1, no_ptr<F>*, 2, 3, 0> zwx, bar, pqs;
            Matrix<3, 1, no_ptr<F>*, 2, 3, 1> zwy, bag, pqt;
            Matrix<3, 1, const no_ptr<F>*, 2, 3, 2> zwz, bab, pqp;
            Matrix<3, 1, const no_ptr<F>*, 2, 3, 3> zww, baa, pqq;
            Matrix<3, 1, const no_ptr<F>*, 3, 0, 0> wxx, arr, qss;
            Matrix<3, 1, no_ptr<F>*, 3, 0, 1> wxy, arg, qst;
            Matrix<3, 1, no_ptr<F>*, 3, 0, 2> wxz, arb, qsp;
            Matrix<3, 1, const no_ptr<F>*, 3, 0, 3> wxw, ara, qsq;
            Matrix<3, 1, no_ptr<F>*, 3, 1, 0> wyx, agr, qts;
            Matrix<3, 1, const no_ptr<F>*, 3, 1, 1> wyy, agg, qtt;
            Matrix<3, 1, no_ptr<F>*, 3, 1, 2> wyz, agb, qtp;
            Matrix<3, 1, const no_ptr<F>*, 3, 1, 3> wyw, aga, qtq;
            Matrix<3, 1, no_ptr<F>*, 3, 2, 0> wzx, abr, qps;
            Matrix<3, 1, no_ptr<F>*, 3, 2, 1> wzy, abg, qpt;
            Matrix<3, 1, const no_ptr<F>*, 3, 2, 2> wzz, abb, qpp;
            Matrix<3, 1, const no_ptr<F>*, 3, 2, 3> wzw, aba, qpq;
            Matrix<3, 1, const no_ptr<F>*, 3, 3, 0> wwx, aar, qqs;
            Matrix<3, 1, const no_ptr<F>*, 3, 3, 1> wwy, aag, qqt;
            Matrix<3, 1, const no_ptr<F>*, 3, 3, 2> wwz, aab, qqp;
            Matrix<3, 1, const no_ptr<F>*, 3, 3, 3> www, aaa, qqq;

            Matrix<4, 1, const no_ptr<F>*, 0, 0, 0, 0> xxxx, rrrr, ssss;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 0, 1> xxxy, rrrg, ssst;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 0, 2> xxxz, rrrb, sssp;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 0, 3> xxxw, rrra, sssq;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 1, 0> xxyx, rrgr, ssts;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 1, 1> xxyy, rrgg, sstt;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 1, 2> xxyz, rrgb, sstp;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 1, 3> xxyw, rrga, sstq;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 2, 0> xxzx, rrbr, ssps;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 2, 1> xxzy, rrbg, sspt;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 2, 2> xxzz, rrbb, sspp;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 2, 3> xxzw, rrba, sspq;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 3, 0> xxwx, rrar, ssqs;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 3, 1> xxwy, rrag, ssqt;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 3, 2> xxwz, rrab, ssqp;
            Matrix<4, 1, const no_ptr<F>*, 0, 0, 3, 3> xxww, rraa, ssqq;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 0, 0> xyxx, rgrr, stss;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 0, 1> xyxy, rgrg, stst;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 0, 2> xyxz, rgrb, stsp;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 0, 3> xyxw, rgra, stsq;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 1, 0> xyyx, rggr, stts;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 1, 1> xyyy, rggg, sttt;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 1, 2> xyyz, rggb, sttp;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 1, 3> xyyw, rgga, sttq;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 2, 0> xyzx, rgbr, stps;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 2, 1> xyzy, rgbg, stpt;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 2, 2> xyzz, rgbb, stpp;
            Matrix<4, 1, no_ptr<F>*, 0, 1, 2, 3> xyzw, rgba, stpq;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 3, 0> xywx, rgar, stqs;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 3, 1> xywy, rgag, stqt;
            Matrix<4, 1, no_ptr<F>*, 0, 1, 3, 2> xywz, rgab, stqp;
            Matrix<4, 1, const no_ptr<F>*, 0, 1, 3, 3> xyww, rgaa, stqq;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 0, 0> xzxx, rbrr, spss;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 0, 1> xzxy, rbrg, spst;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 0, 2> xzxz, rbrb, spsp;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 0, 3> xzxw, rbra, spsq;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 1, 0> xzyx, rbgr, spts;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 1, 1> xzyy, rbgg, sptt;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 1, 2> xzyz, rbgb, sptp;
            Matrix<4, 1, no_ptr<F>*, 0, 2, 1, 3> xzyw, rbga, sptq;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 2, 0> xzzx, rbbr, spps;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 2, 1> xzzy, rbbg, sppt;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 2, 2> xzzz, rbbb, sppp;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 2, 3> xzzw, rbba, sppq;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 3, 0> xzwx, rbar, spqs;
            Matrix<4, 1, no_ptr<F>*, 0, 2, 3, 1> xzwy, rbag, spqt;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 3, 2> xzwz, rbab, spqp;
            Matrix<4, 1, const no_ptr<F>*, 0, 2, 3, 3> xzww, rbaa, spqq;
            Matrix<4, 1, const no_ptr<F>*, 0, 3, 0, 0> xwxx, rarr, sqss;
            Matrix<4, 1, const no_ptr<F>*, 0, 3, 0, 1> xwxy, rarg, sqst;
            Matrix<4, 1, const no_ptr<F>*, 0, 3, 0, 2> xwxz, rarb, sqsp;
            Matrix<4, 1, const no_ptr<F>*, 0, 3, 0, 3> xwxw, rara, sqsq;
            Matrix<4, 1, const no_ptr<F>*, 0, 3, 1, 0> xwyx, ragr, sqts;
            Matrix<4, 1, const no_ptr<F>*, 0, 3, 1, 1> xwyy, ragg, sqtt;
            Matrix<4, 1, no_ptr<F>*, 0, 3, 1, 2> xwyz, ragb, sqtp;
            Matrix<4, 1, const no_ptr<F>*, 0, 3, 1, 3> xwyw, raga, sqtq;
            Matrix<4, 1, const no_ptr<F>*, 0, 3, 2, 0> xwzx, rabr, sqps;
            Matrix<4, 1, no_ptr<F>*, 0, 3, 2, 1> xwzy, rabg, sqpt;
            Matrix<4, 1, const no_ptr<F>*, 0, 3, 2, 2> xwzz, rabb, sqpp;
            Matrix<4, 1, const no_ptr<F>*, 0, 3, 2, 3> xwzw, raba, sqpq;
            Matrix<4, 1, const no_ptr<F>*, 0, 3, 3, 0> xwwx, raar, sqqs;
            Matrix<4, 1, const no_ptr<F>*, 0, 3, 3, 1> xwwy, raag, sqqt;
            Matrix<4, 1, const no_ptr<F>*, 0, 3, 3, 2> xwwz, raab, sqqp;
            Matrix<4, 1, const no_ptr<F>*, 0, 3, 3, 3> xwww, raaa, sqqq;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 0, 0> yxxx, grrr, tsss;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 0, 1> yxxy, grrg, tsst;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 0, 2> yxxz, grrb, tssp;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 0, 3> yxxw, grra, tssq;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 1, 0> yxyx, grgr, tsts;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 1, 1> yxyy, grgg, tstt;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 1, 2> yxyz, grgb, tstp;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 1, 3> yxyw, grga, tstq;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 2, 0> yxzx, grbr, tsps;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 2, 1> yxzy, grbg, tspt;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 2, 2> yxzz, grbb, tspp;
            Matrix<4, 1, no_ptr<F>*, 1, 0, 2, 3> yxzw, grba, tspq;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 3, 0> yxwx, grar, tsqs;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 3, 1> yxwy, grag, tsqt;
            Matrix<4, 1, no_ptr<F>*, 1, 0, 3, 2> yxwz, grab, tsqp;
            Matrix<4, 1, const no_ptr<F>*, 1, 0, 3, 3> yxww, graa, tsqq;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 0, 0> yyxx, ggrr, ttss;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 0, 1> yyxy, ggrg, ttst;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 0, 2> yyxz, ggrb, ttsp;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 0, 3> yyxw, ggra, ttsq;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 1, 0> yyyx, gggr, ttts;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 1, 1> yyyy, gggg, tttt;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 1, 2> yyyz, gggb, tttp;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 1, 3> yyyw, ggga, tttq;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 2, 0> yyzx, ggbr, ttps;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 2, 1> yyzy, ggbg, ttpt;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 2, 2> yyzz, ggbb, ttpp;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 2, 3> yyzw, ggba, ttpq;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 3, 0> yywx, ggar, ttqs;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 3, 1> yywy, ggag, ttqt;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 3, 2> yywz, ggab, ttqp;
            Matrix<4, 1, const no_ptr<F>*, 1, 1, 3, 3> yyww, ggaa, ttqq;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 0, 0> yzxx, gbrr, tpss;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 0, 1> yzxy, gbrg, tpst;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 0, 2> yzxz, gbrb, tpsp;
            Matrix<4, 1, no_ptr<F>*, 1, 2, 0, 3> yzxw, gbra, tpsq;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 1, 0> yzyx, gbgr, tpts;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 1, 1> yzyy, gbgg, tptt;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 1, 2> yzyz, gbgb, tptp;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 1, 3> yzyw, gbga, tptq;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 2, 0> yzzx, gbbr, tpps;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 2, 1> yzzy, gbbg, tppt;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 2, 2> yzzz, gbbb, tppp;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 2, 3> yzzw, gbba, tppq;
            Matrix<4, 1, no_ptr<F>*, 1, 2, 3, 0> yzwx, gbar, tpqs;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 3, 1> yzwy, gbag, tpqt;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 3, 2> yzwz, gbab, tpqp;
            Matrix<4, 1, const no_ptr<F>*, 1, 2, 3, 3> yzww, gbaa, tpqq;
            Matrix<4, 1, const no_ptr<F>*, 1, 3, 0, 0> ywxx, garr, tqss;
            Matrix<4, 1, const no_ptr<F>*, 1, 3, 0, 1> ywxy, garg, tqst;
            Matrix<4, 1, no_ptr<F>*, 1, 3, 0, 2> ywxz, garb, tqsp;
            Matrix<4, 1, const no_ptr<F>*, 1, 3, 0, 3> ywxw, gara, tqsq;
            Matrix<4, 1, const no_ptr<F>*, 1, 3, 1, 0> ywyx, gagr, tqts;
            Matrix<4, 1, const no_ptr<F>*, 1, 3, 1, 1> ywyy, gagg, tqtt;
            Matrix<4, 1, const no_ptr<F>*, 1, 3, 1, 2> ywyz, gagb, tqtp;
            Matrix<4, 1, const no_ptr<F>*, 1, 3, 1, 3> ywyw, gaga, tqtq;
            Matrix<4, 1, no_ptr<F>*, 1, 3, 2, 0> ywzx, gabr, tqps;
            Matrix<4, 1, const no_ptr<F>*, 1, 3, 2, 1> ywzy, gabg, tqpt;
            Matrix<4, 1, const no_ptr<F>*, 1, 3, 2, 2> ywzz, gabb, tqpp;
            Matrix<4, 1, const no_ptr<F>*, 1, 3, 2, 3> ywzw, gaba, tqpq;
            Matrix<4, 1, const no_ptr<F>*, 1, 3, 3, 0> ywwx, gaar, tqqs;
            Matrix<4, 1, const no_ptr<F>*, 1, 3, 3, 1> ywwy, gaag, tqqt;
            Matrix<4, 1, const no_ptr<F>*, 1, 3, 3, 2> ywwz, gaab, tqqp;
            Matrix<4, 1, const no_ptr<F>*, 1, 3, 3, 3> ywww, gaaa, tqqq;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 0, 0> zxxx, brrr, psss;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 0, 1> zxxy, brrg, psst;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 0, 2> zxxz, brrb, pssp;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 0, 3> zxxw, brra, pssq;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 1, 0> zxyx, brgr, psts;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 1, 1> zxyy, brgg, pstt;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 1, 2> zxyz, brgb, pstp;
            Matrix<4, 1, no_ptr<F>*, 2, 0, 1, 3> zxyw, brga, pstq;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 2, 0> zxzx, brbr, psps;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 2, 1> zxzy, brbg, pspt;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 2, 2> zxzz, brbb, pspp;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 2, 3> zxzw, brba, pspq;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 3, 0> zxwx, brar, psqs;
            Matrix<4, 1, no_ptr<F>*, 2, 0, 3, 1> zxwy, brag, psqt;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 3, 2> zxwz, brab, psqp;
            Matrix<4, 1, const no_ptr<F>*, 2, 0, 3, 3> zxww, braa, psqq;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 0, 0> zyxx, bgrr, ptss;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 0, 1> zyxy, bgrg, ptst;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 0, 2> zyxz, bgrb, ptsp;
            Matrix<4, 1, no_ptr<F>*, 2, 1, 0, 3> zyxw, bgra, ptsq;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 1, 0> zyyx, bggr, ptts;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 1, 1> zyyy, bggg, pttt;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 1, 2> zyyz, bggb, pttp;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 1, 3> zyyw, bgga, pttq;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 2, 0> zyzx, bgbr, ptps;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 2, 1> zyzy, bgbg, ptpt;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 2, 2> zyzz, bgbb, ptpp;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 2, 3> zyzw, bgba, ptpq;
            Matrix<4, 1, no_ptr<F>*, 2, 1, 3, 0> zywx, bgar, ptqs;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 3, 1> zywy, bgag, ptqt;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 3, 2> zywz, bgab, ptqp;
            Matrix<4, 1, const no_ptr<F>*, 2, 1, 3, 3> zyww, bgaa, ptqq;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 0, 0> zzxx, bbrr, ppss;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 0, 1> zzxy, bbrg, ppst;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 0, 2> zzxz, bbrb, ppsp;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 0, 3> zzxw, bbra, ppsq;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 1, 0> zzyx, bbgr, ppts;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 1, 1> zzyy, bbgg, pptt;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 1, 2> zzyz, bbgb, pptp;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 1, 3> zzyw, bbga, pptq;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 2, 0> zzzx, bbbr, ppps;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 2, 1> zzzy, bbbg, pppt;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 2, 2> zzzz, bbbb, pppp;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 2, 3> zzzw, bbba, pppq;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 3, 0> zzwx, bbar, ppqs;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 3, 1> zzwy, bbag, ppqt;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 3, 2> zzwz, bbab, ppqp;
            Matrix<4, 1, const no_ptr<F>*, 2, 2, 3, 3> zzww, bbaa, ppqq;
            Matrix<4, 1, const no_ptr<F>*, 2, 3, 0, 0> zwxx, barr, pqss;
            Matrix<4, 1, no_ptr<F>*, 2, 3, 0, 1> zwxy, barg, pqst;
            Matrix<4, 1, const no_ptr<F>*, 2, 3, 0, 2> zwxz, barb, pqsp;
            Matrix<4, 1, const no_ptr<F>*, 2, 3, 0, 3> zwxw, bara, pqsq;
            Matrix<4, 1, no_ptr<F>*, 2, 3, 1, 0> zwyx, bagr, pqts;
            Matrix<4, 1, const no_ptr<F>*, 2, 3, 1, 1> zwyy, bagg, pqtt;
            Matrix<4, 1, const no_ptr<F>*, 2, 3, 1, 2> zwyz, bagb, pqtp;
            Matrix<4, 1, const no_ptr<F>*, 2, 3, 1, 3> zwyw, baga, pqtq;
            Matrix<4, 1, const no_ptr<F>*, 2, 3, 2, 0> zwzx, babr, pqps;
            Matrix<4, 1, const no_ptr<F>*, 2, 3, 2, 1> zwzy, babg, pqpt;
            Matrix<4, 1, const no_ptr<F>*, 2, 3, 2, 2> zwzz, babb, pqpp;
            Matrix<4, 1, const no_ptr<F>*, 2, 3, 2, 3> zwzw, baba, pqpq;
            Matrix<4, 1, const no_ptr<F>*, 2, 3, 3, 0> zwwx, baar, pqqs;
            Matrix<4, 1, const no_ptr<F>*, 2, 3, 3, 1> zwwy, baag, pqqt;
            Matrix<4, 1, const no_ptr<F>*, 2, 3, 3, 2> zwwz, baab, pqqp;
            Matrix<4, 1, const no_ptr<F>*, 2, 3, 3, 3> zwww, baaa, pqqq;
            Matrix<4, 1, const no_ptr<F>*, 3, 0, 0, 0> wxxx, arrr, qsss;
            Matrix<4, 1, const no_ptr<F>*, 3, 0, 0, 1> wxxy, arrg, qsst;
            Matrix<4, 1, const no_ptr<F>*, 3, 0, 0, 2> wxxz, arrb, qssp;
            Matrix<4, 1, const no_ptr<F>*, 3, 0, 0, 3> wxxw, arra, qssq;
            Matrix<4, 1, const no_ptr<F>*, 3, 0, 1, 0> wxyx, argr, qsts;
            Matrix<4, 1, const no_ptr<F>*, 3, 0, 1, 1> wxyy, argg, qstt;
            Matrix<4, 1, no_ptr<F>*, 3, 0, 1, 2> wxyz, argb, qstp;
            Matrix<4, 1, const no_ptr<F>*, 3, 0, 1, 3> wxyw, arga, qstq;
            Matrix<4, 1, const no_ptr<F>*, 3, 0, 2, 0> wxzx, arbr, qsps;
            Matrix<4, 1, no_ptr<F>*, 3, 0, 2, 1> wxzy, arbg, qspt;
            Matrix<4, 1, const no_ptr<F>*, 3, 0, 2, 2> wxzz, arbb, qspp;
            Matrix<4, 1, const no_ptr<F>*, 3, 0, 2, 3> wxzw, arba, qspq;
            Matrix<4, 1, const no_ptr<F>*, 3, 0, 3, 0> wxwx, arar, qsqs;
            Matrix<4, 1, const no_ptr<F>*, 3, 0, 3, 1> wxwy, arag, qsqt;
            Matrix<4, 1, const no_ptr<F>*, 3, 0, 3, 2> wxwz, arab, qsqp;
            Matrix<4, 1, const no_ptr<F>*, 3, 0, 3, 3> wxww, araa, qsqq;
            Matrix<4, 1, const no_ptr<F>*, 3, 1, 0, 0> wyxx, agrr, qtss;
            Matrix<4, 1, const no_ptr<F>*, 3, 1, 0, 1> wyxy, agrg, qtst;
            Matrix<4, 1, no_ptr<F>*, 3, 1, 0, 2> wyxz, agrb, qtsp;
            Matrix<4, 1, const no_ptr<F>*, 3, 1, 0, 3> wyxw, agra, qtsq;
            Matrix<4, 1, const no_ptr<F>*, 3, 1, 1, 0> wyyx, aggr, qtts;
            Matrix<4, 1, const no_ptr<F>*, 3, 1, 1, 1> wyyy, aggg, qttt;
            Matrix<4, 1, const no_ptr<F>*, 3, 1, 1, 2> wyyz, aggb, qttp;
            Matrix<4, 1, const no_ptr<F>*, 3, 1, 1, 3> wyyw, agga, qttq;
            Matrix<4, 1, no_ptr<F>*, 3, 1, 2, 0> wyzx, agbr, qtps;
            Matrix<4, 1, const no_ptr<F>*, 3, 1, 2, 1> wyzy, agbg, qtpt;
            Matrix<4, 1, const no_ptr<F>*, 3, 1, 2, 2> wyzz, agbb, qtpp;
            Matrix<4, 1, const no_ptr<F>*, 3, 1, 2, 3> wyzw, agba, qtpq;
            Matrix<4, 1, const no_ptr<F>*, 3, 1, 3, 0> wywx, agar, qtqs;
            Matrix<4, 1, const no_ptr<F>*, 3, 1, 3, 1> wywy, agag, qtqt;
            Matrix<4, 1, const no_ptr<F>*, 3, 1, 3, 2> wywz, agab, qtqp;
            Matrix<4, 1, const no_ptr<F>*, 3, 1, 3, 3> wyww, agaa, qtqq;
            Matrix<4, 1, const no_ptr<F>*, 3, 2, 0, 0> wzxx, abrr, qpss;
            Matrix<4, 1, no_ptr<F>*, 3, 2, 0, 1> wzxy, abrg, qpst;
            Matrix<4, 1, const no_ptr<F>*, 3, 2, 0, 2> wzxz, abrb, qpsp;
            Matrix<4, 1, const no_ptr<F>*, 3, 2, 0, 3> wzxw, abra, qpsq;
            Matrix<4, 1, no_ptr<F>*, 3, 2, 1, 0> wzyx, abgr, qpts;
            Matrix<4, 1, const no_ptr<F>*, 3, 2, 1, 1> wzyy, abgg, qptt;
            Matrix<4, 1, const no_ptr<F>*, 3, 2, 1, 2> wzyz, abgb, qptp;
            Matrix<4, 1, const no_ptr<F>*, 3, 2, 1, 3> wzyw, abga, qptq;
            Matrix<4, 1, const no_ptr<F>*, 3, 2, 2, 0> wzzx, abbr, qpps;
            Matrix<4, 1, const no_ptr<F>*, 3, 2, 2, 1> wzzy, abbg, qppt;
            Matrix<4, 1, const no_ptr<F>*, 3, 2, 2, 2> wzzz, abbb, qppp;
            Matrix<4, 1, const no_ptr<F>*, 3, 2, 2, 3> wzzw, abba, qppq;
            Matrix<4, 1, const no_ptr<F>*, 3, 2, 3, 0> wzwx, abar, qpqs;
            Matrix<4, 1, const no_ptr<F>*, 3, 2, 3, 1> wzwy, abag, qpqt;
            Matrix<4, 1, const no_ptr<F>*, 3, 2, 3, 2> wzwz, abab, qpqp;
            Matrix<4, 1, const no_ptr<F>*, 3, 2, 3, 3> wzww, abaa, qpqq;
            Matrix<4, 1, const no_ptr<F>*, 3, 3, 0, 0> wwxx, aarr, qqss;
            Matrix<4, 1, const no_ptr<F>*, 3, 3, 0, 1> wwxy, aarg, qqst;
            Matrix<4, 1, const no_ptr<F>*, 3, 3, 0, 2> wwxz, aarb, qqsp;
            Matrix<4, 1, const no_ptr<F>*, 3, 3, 0, 3> wwxw, aara, qqsq;
            Matrix<4, 1, const no_ptr<F>*, 3, 3, 1, 0> wwyx, aagr, qqts;
            Matrix<4, 1, const no_ptr<F>*, 3, 3, 1, 1> wwyy, aagg, qqtt;
            Matrix<4, 1, const no_ptr<F>*, 3, 3, 1, 2> wwyz, aagb, qqtp;
            Matrix<4, 1, const no_ptr<F>*, 3, 3, 1, 3> wwyw, aaga, qqtq;
            Matrix<4, 1, const no_ptr<F>*, 3, 3, 2, 0> wwzx, aabr, qqps;
            Matrix<4, 1, const no_ptr<F>*, 3, 3, 2, 1> wwzy, aabg, qqpt;
            Matrix<4, 1, const no_ptr<F>*, 3, 3, 2, 2> wwzz, aabb, qqpp;
            Matrix<4, 1, const no_ptr<F>*, 3, 3, 2, 3> wwzw, aaba, qqpq;
            Matrix<4, 1, const no_ptr<F>*, 3, 3, 3, 0> wwwx, aaar, qqqs;
            Matrix<4, 1, const no_ptr<F>*, 3, 3, 3, 1> wwwy, aaag, qqqt;
            Matrix<4, 1, const no_ptr<F>*, 3, 3, 3, 2> wwwz, aaab, qqqp;
            Matrix<4, 1, const no_ptr<F>*, 3, 3, 3, 3> wwww, aaaa, qqqq;
        };
    };
}

using uint = unsigned;

#ifndef UINT64_C
using int64_t = long long;
using uint64_t = unsigned long long;
#endif

using ivec2 = glsl::Matrix<2, 1, int, 0, 1>;
using ivec3 = glsl::Matrix<3, 1, int, 0, 1, 2>;
using ivec4 = glsl::Matrix<4, 1, int, 0, 1, 2, 3>;

using uvec2 = glsl::Matrix<2, 1, uint, 0, 1>;
using uvec3 = glsl::Matrix<3, 1, uint, 0, 1, 2>;
using uvec4 = glsl::Matrix<4, 1, uint, 0, 1, 2, 3>;

using i64vec2 = glsl::Matrix<2, 1, int64_t, 0, 1>;
using i64vec3 = glsl::Matrix<3, 1, int64_t, 0, 1, 2>;
using i64vec4 = glsl::Matrix<4, 1, int64_t, 0, 1, 2, 3>;

using u64vec2 = glsl::Matrix<2, 1, uint64_t, 0, 1>;
using u64vec3 = glsl::Matrix<3, 1, uint64_t, 0, 1, 2>;
using u64vec4 = glsl::Matrix<4, 1, uint64_t, 0, 1, 2, 3>;

using bvec2 = glsl::Matrix<2, 1, bool, 0, 1>;
using bvec3 = glsl::Matrix<3, 1, bool, 0, 1, 2>;
using bvec4 = glsl::Matrix<4, 1, bool, 0, 1, 2, 3>;

using vec2 = glsl::Matrix<2, 1, float, 0, 1>;
using vec3 = glsl::Matrix<3, 1, float, 0, 1, 2>;
using vec4 = glsl::Matrix<4, 1, float, 0, 1, 2, 3>;

using dvec2 = glsl::Matrix<2, 1, double, 0, 1>;
using dvec3 = glsl::Matrix<3, 1, double, 0, 1, 2>;
using dvec4 = glsl::Matrix<4, 1, double, 0, 1, 2, 3>;

using mat2x2 = glsl::Matrix<2, 2, float, 0, 1, 2, 3>;
using mat2x3 = glsl::Matrix<3, 2, float, 0, 1, 2, 3, 4, 5>;
using mat2x4 = glsl::Matrix<4, 2, float, 0, 1, 2, 3, 4, 5, 6, 7>;

using mat3x2 = glsl::Matrix<2, 3, float, 0, 1, 2, 3, 4, 5>;
using mat3x3 = glsl::Matrix<3, 3, float, 0, 1, 2, 3, 4, 5, 6, 7, 8>;
using mat3x4 = glsl::Matrix<4, 3, float, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>;

using mat4x2 = glsl::Matrix<2, 4, float, 0, 1, 2, 3, 4, 5, 6, 7>;
using mat4x3 = glsl::Matrix<3, 4, float, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>;
using mat4x4 = glsl::Matrix<4, 4, float, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>;

using mat2 = mat2x2;
using mat3 = mat3x3;
using mat4 = mat4x4;

using dmat2x2 = glsl::Matrix<2, 2, double, 0, 1, 2, 3>;
using dmat2x3 = glsl::Matrix<3, 2, double, 0, 1, 2, 3, 4, 5>;
using dmat2x4 = glsl::Matrix<4, 2, double, 0, 1, 2, 3, 4, 5, 6, 7>;

using dmat3x2 = glsl::Matrix<2, 3, double, 0, 1, 2, 3, 4, 5>;
using dmat3x3 = glsl::Matrix<3, 3, double, 0, 1, 2, 3, 4, 5, 6, 7, 8>;
using dmat3x4 = glsl::Matrix<4, 3, double, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>;

using dmat4x2 = glsl::Matrix<2, 4, double, 0, 1, 2, 3, 4, 5, 6, 7>;
using dmat4x3 = glsl::Matrix<3, 4, double, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>;
using dmat4x4 = glsl::Matrix<4, 4, double, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>;

using dmat2 = dmat2x2;
using dmat3 = dmat3x3;
using dmat4 = dmat4x4;

#include <cmath>
#include <cstring>

namespace glsl {

    template<typename M, int... I>
    inline auto sum(const M& a, const M& b, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return a + b;
        else return M(a.data[I] + b.data[I] ...);
    }
    template<typename M, int... I>
    inline auto sub(const M& a, const M& b, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return a - b;
        else return M(a.data[I] - b.data[I] ...);
    }
    template<typename M, int... I>
    inline auto neg(const M& a, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return -a;
        else return M(-a.data[I] ...);
    }
    template<typename M, int... I>
    inline auto div(const M& a, const M& b, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return a / b;
        else return M(a.data[I] / b.data[I] ...);
    }
    template<typename F>
    constexpr bool integral = same<const F, const int> || same<const F, const uint> || same<const F, const int64_t> || same<const F, const uint64_t>;
    template<typename First, typename Second>
    constexpr bool moddable = integral<First> && integral<Second>;

    template<typename M, int... I>
    inline auto mod(const M& a, const M& b, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return a % b;
        else return M(a.data[I] % b.data[I] ...);
    }
    template<typename M, int... I>
    inline auto bin_neg(const M& a, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return -a;
        else return M(~a.data[I] ...);
    }
    template<typename M, int... I>
    inline auto lshift(const M& a, const M& b, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return a << b;
        else return M(a.data[I] << b.data[I] ...);
    }
    template<typename M, int... I>
    inline auto rshift(const M& a, const M& b, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return a >> b;
        else return M(a.data[I] >> b.data[I] ...);
    }
    template<typename M, int... I>
    inline auto and_(const M& a, const M& b, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return a & b;
        else return M(a.data[I] & b.data[I] ...);
    }
    template<typename M, int... I>
    inline auto or_(const M& a, const M& b, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return a | b;
        else return M(a.data[I] | b.data[I] ...);
    }
    template<typename M, int... I>
    inline auto xor_(const M & a, const M & b, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return a ^ b;
        else return M(a.data[I] ^ b.data[I] ...);
    }
    template<typename M, int... I>
    inline bool equals(const M& a, const M& b, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return a == b;
        else return ((a.data[I] == b.data[I]) && ...);
    }
    template<typename M, int... I>
    inline auto mul(const M& a, const M& b, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return a * b;
        else return M(a.data[I] * b.data[I] ...);
    }
    template<typename M1, typename M2, int... I, int... K>
    inline auto matmul(const M1& a, const M2& b, sequence<I...>, sequence<K...>, MultCommon<M1, M2> result = {}) {
        int i;
        if constexpr (Columns<M1> == 1) return ((i = I, result.data[i] = ((a.data[K] * b.data[K + (i / Columns<MultCommon<M1, M2>>) * Rows<M2>]) + ...)), ..., result);
        else {
            constexpr int result_rows = Rows<MultCommon<M1, M2>>;
            return ((i = I, result.data[i] = ((a.data[(i % result_rows) + K * Rows<M1>] * b.data[K + (i / result_rows) * Rows<M2>]) + ...)), ..., result);
        }
    }
    template<typename M, int... I>
    inline auto maximum(const M& a, const M& b, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return (a > b) ? a : b;
        else return M((a.data[I] > b.data[I]) ? a.data[I] : b.data[I] ...);
    }
    template<typename M, int... I>
    inline auto mininum(const M& a, const M& b, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return (a < b) ? a : b;
        else return M((a.data[I] < b.data[I]) ? a.data[I] : b.data[I] ...);
    }
    template<typename M, int... I>
    inline auto absolute(const M& x, sequence<I...>) {
        constexpr Field<M> zero(0);
        if constexpr (sizeof...(I) == 1) return (x < zero) ? -x : x;
        else return M((x.data[I] < zero) ? -x.data[I] : x.data[I] ...);
    }

    template<typename M, int... I>
    auto lt(const M& a, const M& b, sequence<I...>) {
        return Matrix<Rows<M>, 1, bool, I...>((a.data[I] < b.data[I]) ...);
    }
    template<typename M, int... I>
    auto lte(const M& a, const M& b, sequence<I...>) {
        return Matrix<Rows<M>, 1, bool, I...>((a.data[I] <= b.data[I]) ...);
    }
    template<typename M, int... I>
    auto gt(const M& a, const M& b, sequence<I...>) {
        return Matrix<Rows<M>, 1, bool, I...>((a.data[I] > b.data[I]) ...);
    }
    template<typename M, int... I>
    auto gte(const M& a, const M& b, sequence<I...>) {
        return Matrix<Rows<M>, 1, bool, I...>((a.data[I] >= b.data[I]) ...);
    }
    template<typename M, int... I>
    auto eq(const M& a, const M& b, sequence<I...>) {
        return Matrix<Rows<M>, 1, bool, I...>((a.data[I] == b.data[I]) ...);
    }
    template<typename M, int... I>
    auto neq(const M& a, const M& b, sequence<I...>) {
        return Matrix<Rows<M>, 1, bool, I...>((a.data[I] != b.data[I]) ...);
    }

    template<typename M, int... I>
    auto not_(const M& x, sequence<I...>) {
        return M(!x.data[I]...);
    }
    template<typename M, int... I>
    auto isnan(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::isnan(x);
        else return Matrix<Rows<M>, Columns<M>, bool, I...>(std::isnan(x.data[I])...);
    }
    template<typename M, int... I>
    auto isinf(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::isinf(x);
        else return Matrix<Rows<M>, Columns<M>, bool, I...>(std::isinf(x.data[I])...);
    }

    template<typename M, int... I>
    inline auto ceiling(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::ceil(float(x));
        else return M(std::ceil(float(x.data[I])) ...);
    }
    template<typename M, int... I>
    inline auto flooring(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::floor(float(x));
        else return M(std::floor(float(x.data[I])) ...);
    }
    template<typename M, int... I>
    inline auto fraction(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return x - std::floor(float(x));
        else return M(x.data[I] - std::floor(float(x.data[I])) ...);
    }
    template<typename M, int... I>
    inline auto rounder(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::round(float(x));
        else return M(std::round(x.data[I]) ...);
    }
    template<typename M, int... I>
    inline auto modulus(const M& x, const M& y, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return x - y * std::floor(float(x / y));
        else return M(x.data[I] - y.data[I] * std::floor(float(x.data[I] / y.data[I])) ...);
    }
    template<typename M, int... I>
    inline auto power(const M& x, const M& y, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::pow(float(x), float(y));
        else return M(std::pow(float(x.data[I]), float(y.data[I])) ...);
    }
    template<typename M, int... I>
    inline auto clamper(const M& x, const M& v, const M& V, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return (x < v) ? v : ((x > V) ? V : x);
        else return M((x.data[I] < v.data[I]) ? v.data[I] : ((x.data[I] > V.data[I]) ? V.data[I] : x.data[I]) ...);
    }
    template<typename M, int... I>
    inline auto mixer(const M& x, const M& y, const M& a, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return x * (1 - a) + y * a;
        else return M(x.data[I] * (1 - a.data[I]) + y.data[I] * a.data[I] ...);
    }
    template<typename M, int... I>
    inline auto smoothstepper(const M& e0, const M& e1, const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) {
            M t = (x - e0) / (e1 - e0);
            t = t < 0 ? 0 : (t > 1 ? 1 : t);
            return t * t * (3 - 2 * t);
        }
        else {
            M t;
            ((t.data[I] = (x.data[I] - e0.data[I]) / (e1.data[I] - e0.data[I])), ...);
            ((t.data[I] = t.data[I] < 0 ? 0 : (t.data[I] > 1 ? 1 : t.data[I])), ...);
            return M(t.data[I] * t.data[I] * (3 - 2 * t.data[I]) ...);
        }
    }
    template<typename M, int... I>
    inline auto stepper(const M& edge, const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return x < edge ? 0 : 1;
        else return M(x.data[I] < edge.data[I] ? 0 : 1 ...);
    }
    template<typename M, int... I>
    inline auto sine(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::sin(x);
        else return M(std::sin(x.data[I]) ...);
    }
    template<typename M, int... I>
    inline auto arcussine(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::asin(x);
        else return M(std::asin(x.data[I]) ...);
    }
    template<typename M, int... I>
    inline auto cosine(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::cos(x);
        else return M(std::cos(x.data[I]) ...);
    }
    template<typename M, int... I>
    inline auto arcuscosine(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::acos(x);
        else return M(std::acos(x.data[I]) ...);
    }
    template<typename M, int... I>
    inline auto tangent(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::tan(x);
        else return M(std::tan(x.data[I]) ...);
    }
    template<typename M, int... I>
    inline auto arcustangent(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::atan(x);
        else return M(std::tan(x.data[I]) ...);
    }
    template<typename M, int... I>
    inline auto arcustangent(const M& y, const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::atan2(y, x);
        else return M(std::atan2(y.data[I], x.data[I]) ...);
    }
    template<typename M, int... I>
    inline auto to_degrees(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return x * 180.f / 3.14159265358979f;
        else return M(x.data[I] * 180.f / 3.14159265358979f ...);
    }
    template<typename M, int... I>
    inline auto to_radians(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return x * 3.14159265358979f / 180.f;
        else return M(x.data[I] * 3.14159265358979f / 180.f ...);
    }

    template<typename M, int... I>
    inline auto dotter(const M& x, const M& y, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return x * y;
        else return ((x.data[I] * y.data[I]) + ...);
    }
    template<typename M, int... I>
    inline auto len(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::fabs(x);
        else return std::sqrt(((x.data[I] * x.data[I]) + ...));
    }
    template<typename M, int... I>
    inline auto square_root(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::sqrt(x);
        else return M(std::sqrt(x.data[I]) ...);
    }
    template<typename M, int... I>
    inline auto exper(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::exp(x);
        else return M(std::exp(x.data[I]) ...);
    }
    template<typename M, int... I>
    inline auto exp2er(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::exp2(x);
        else return M(std::exp2f(x.data[I]) ...);
    }
    template<typename M, int... I>
    inline auto loger(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::log(x);
        else return M(std::log(x.data[I]) ...);
    }
    template<typename M, int... I>
    inline auto log2er(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return std::log2(x);
        else return M(std::log2(x.data[I]) ...);
    }
    template<typename M, int... I>
    inline auto signum(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) return M((x < 0) ? (-1) : ((x > 0) ? 1 : 0));
        else return M((x.data[I] < 0) ? (-1) : ((x.data[I] > 0) ? 1 : 0) ...);
    }
    template<typename F, typename M, int... I>
    inline auto cast(const M& x, sequence<I...>) {
        if constexpr (sizeof...(I) == 1) {
            F result; memcpy(&result, &x, sizeof(F));
            return result;
        }
        else {
            identity<Rows<M>, Columns<M>, F> result;
            memcpy(result.data, x.data, sizeof(F) * sizeof...(I));
            return result;
        }
    }
    template<typename M1, typename M2, int... I>
    inline auto outer(const M1& c, const M2& r, sequence<I...>) {
        constexpr int R1 = Rows<M1>, R2 = Rows<M2>;
        return identity<R1, R2, decltype(c.data[0]*r.data[0])>((c[I/R1]*r[I%R1]) ...);
    }

    template<typename genType, typename genType_, typename = enable<(Rows<genType> > 1 || Rows<genType_> > 1) && broadcastable<genType, genType_>> >
    inline Common<genType, genType_> operator+(const genType& x, const genType_& y) {
        return sum(Common<genType, genType_>(x), Common<genType, genType_>(y), Iota<genType, genType_>{});
    }

    template<typename genType, typename genType_, typename = enable<(Rows<genType> > 1 || Rows<genType_> > 1) && broadcastable<genType, genType_>> >
    inline Common<genType, genType_> operator-(const genType& x, const genType_& y) {
        return sub(Common<genType, genType_>(x), Common<genType, genType_>(y), Iota<genType, genType_>{});
    }

    template<typename genType, typename = enable<(Rows<genType> > 1)>>
    inline auto operator-(const genType& x) {
        return neg(identity<Rows<genType>, Columns<genType>, Field<genType>>(x), iota<Rows<genType>* Columns<genType>>{});
    }

    template<typename genType, typename genType_, typename = enable<(Rows<genType> > 1 || Rows<genType_> > 1) && broadcastable<genType, genType_>> >
    inline Common<genType, genType_> operator/(const genType& x, const genType_& y) {
        return div(Common<genType, genType_>(x), Common<genType, genType_>(y), Iota<genType, genType_>{});
    }

    template<typename genType, typename genType_, typename = enable<(Rows<genType> > 1 || Rows<genType_> > 1) && broadcastable<genType, genType_> && moddable<Field<genType>, Field<genType_>>> >
    inline auto operator%(const genType& x, const genType_& y) {
        return mod(Common<genType, genType_>(x), Common<genType, genType_>(y), Iota<genType, genType_>{});
    }
    template<typename genType, typename = enable<(Rows<genType> > 1) && integral<Field<genType>>>>
    inline auto operator~(const genType& x) {
        return bin_neg(identity<Rows<genType>, Columns<genType>, Field<genType>>(x), iota<Rows<genType>* Columns<genType>>{});
    }
    template<typename genType, typename genType_, typename = enable<(Rows<genType> > 1 || Rows<genType_> > 1) && broadcastable<genType, genType_>&& moddable<Field<genType>, Field<genType_>>> >
    inline auto operator<<(const genType& x, const genType_& y) {
        return lshift(Common<genType, genType_>(x), Common<genType, genType_>(y), Iota<genType, genType_>{});
    }
    template<typename genType, typename genType_, typename = enable<(Rows<genType> > 1 || Rows<genType_> > 1) && broadcastable<genType, genType_>&& moddable<Field<genType>, Field<genType_>>> >
    inline auto operator>>(const genType& x, const genType_& y) {
        return rshift(Common<genType, genType_>(x), Common<genType, genType_>(y), Iota<genType, genType_>{});
    }
    template<typename genType, typename genType_, typename = enable<(Rows<genType> > 1 || Rows<genType_> > 1) && broadcastable<genType, genType_>&& moddable<Field<genType>, Field<genType_>>> >
    inline auto operator&(const genType& x, const genType_& y) {
        return and_(Common<genType, genType_>(x), Common<genType, genType_>(y), Iota<genType, genType_>{});
    }
    template<typename genType, typename genType_, typename = enable<(Rows<genType> > 1 || Rows<genType_> > 1) && broadcastable<genType, genType_>&& moddable<Field<genType>, Field<genType_>>> >
    inline auto operator|(const genType& x, const genType_& y) {
        return or_(Common<genType, genType_>(x), Common<genType, genType_>(y), Iota<genType, genType_>{});
    }
    template<typename genType, typename genType_, typename = enable<(Rows<genType> > 1 || Rows<genType_> > 1) && broadcastable<genType, genType_>&& moddable<Field<genType>, Field<genType_>>> >
    inline auto operator^(const genType& x, const genType_& y) {
        return xor_(Common<genType, genType_>(x), Common<genType, genType_>(y), Iota<genType, genType_>{});
    }
    template<typename genType, typename genType_, typename = enable<(Rows<genType> > 1 || Rows<genType_> > 1) && broadcastable<genType, genType_>>>
    inline bool operator==(const genType& x, const genType_& y) {
        return equals(Common<genType, genType_>(x), Common<genType, genType_>(y), Iota<genType, genType_>{});
    }
    template<typename genType, typename genType_, typename = enable<(Rows<genType> > 1 || Rows<genType_> > 1) && broadcastable<genType, genType_>>>
    inline auto operator!=(const genType& x, const genType_& y) {
        return !equals(Common<genType, genType_>(x), Common<genType, genType_>(y), Iota<genType, genType_>{});
    }

    template<typename genType, typename genType_, typename = enable<(Rows<genType> > 1 || Rows<genType_> > 1) && matmul_broadcastable<genType, genType_>>>
    inline MultCommon<genType, genType_> operator*(const genType& x, const genType_& y) {
        if constexpr (Columns<genType> == 1 && Columns<genType_> == 1 || (Rows<genType> == 1 && Columns<genType> == 1 || Rows<genType_> == 1 && Columns<genType_> == 1))
            return mul(Common<genType, genType_>(x), Common<genType, genType_>(y), Iota<genType, genType_>{});
        else
            return matmul(
                identity<Rows<genType>, Columns<genType>, Field<genType>>(x),
                identity<Rows<genType_>, Columns<genType_>, Field<genType_>>(y),
                iota<mult_iota_length<genType, genType_>()>{},
                iota<Rows<genType_>>{});
    }
}

template<typename genType, typename genType_, typename = glsl::enable<(glsl::Rows<genType> > 1 && glsl::Rows<genType_> > 1) && glsl::Columns<genType> == 1 && glsl::Columns<genType_> == 1>>
inline auto outerProduct(const genType& c, const genType_& r) {
    return glsl::outer(c, r, glsl::iota< glsl::Rows<genType>* glsl::Rows<genType_>>{});
}

template<int R, int... I>
inline bool any(const glsl::Matrix<R, 1, bool, I...>& x) {
    return (x.data[I] || ...);
}
template<int R, int... I>
inline bool all(const glsl::Matrix<R, 1, bool, I...>& x) {
    return (x.data[I] && ...);
}
template<int R, int... I>
inline glsl::Matrix<R, 1, bool, I...> not_(const glsl::Matrix<R, 1, bool, I...>& x) {
    return glsl::not_(x, glsl::iota<R>{});
}

//#define not not_ // gcc doesn't enjoy this; glsl code should just use not_ then I guess

template<typename genType, typename genType_, typename = glsl::enable<glsl::broadcastable<genType, genType_> && glsl::same<const glsl::Field<genType>, const glsl::Field<genType_>>>>
auto lessThan(const genType& x, const genType_& y) {
    return glsl::lt(glsl::Common<genType, genType_>(x), glsl::Common<genType, genType_>(y), glsl::Iota<genType, genType_>{});
}
template<typename genType, typename genType_, typename = glsl::enable<glsl::broadcastable<genType, genType_>&& glsl::same<const glsl::Field<genType>, const glsl::Field<genType_>>>>
auto lessThanEqual(const genType& x, const genType_& y) {
    return glsl::lte(glsl::Common<genType, genType_>(x), glsl::Common<genType, genType_>(y), glsl::Iota<genType, genType_>{});
}
template<typename genType, typename genType_, typename = glsl::enable<glsl::broadcastable<genType, genType_>&& glsl::same<const glsl::Field<genType>, const glsl::Field<genType_>>>>
auto greaterThan(const genType& x, const genType_& y) {
    return glsl::gt(glsl::Common<genType, genType_>(x), glsl::Common<genType, genType_>(y), glsl::Iota<genType, genType_>{});
}
template<typename genType, typename genType_, typename = glsl::enable<glsl::broadcastable<genType, genType_>&& glsl::same<const glsl::Field<genType>, const glsl::Field<genType_>>>>
auto greaterThanEqual(const genType& x, const genType_& y) {
    return glsl::gte(glsl::Common<genType, genType_>(x), glsl::Common<genType, genType_>(y), glsl::Iota<genType, genType_>{});
}
template<typename genType, typename genType_, typename = glsl::enable<glsl::broadcastable<genType, genType_>&& glsl::same<const glsl::Field<genType>, const glsl::Field<genType_>>>>
auto equal(const genType& x, const genType_& y) {
    return glsl::eq(glsl::Common<genType, genType_>(x), glsl::Common<genType, genType_>(y), glsl::Iota<genType, genType_>{});
}
template<typename genType, typename genType_, typename = glsl::enable<glsl::broadcastable<genType, genType_>&& glsl::same<const glsl::Field<genType>, const glsl::Field<genType_>>>>
auto notEqual(const genType& x, const genType_& y) {
    return glsl::neq(glsl::Common<genType, genType_>(x), glsl::Common<genType, genType_>(y), glsl::Iota<genType, genType_>{});
}

template<typename genType>
inline auto isnan_(const genType& x) {
    return glsl::isnan(glsl::Common<genType>(x), glsl::Iota<genType>{});
}
template<typename genType>
inline auto isinf_(const genType& x) {
    return glsl::isinf(glsl::Common<genType>(x), glsl::Iota<genType>{});
}
#define isnan isnan_
#define isinf isinf_

template<typename genType, typename genType_, typename = glsl::enable<glsl::broadcastable<genType, genType_>> >
inline auto max(const genType& x, const genType_& y) {
    return glsl::maximum(glsl::Common<genType, genType_>(x), glsl::Common<genType, genType_>(y), glsl::Iota<genType, genType_>{});
}

template<typename genType, typename genType_, typename = glsl::enable<glsl::broadcastable<genType, genType_>> >
inline auto min(const genType& x, const genType_& y) {
    return glsl::mininum(glsl::Common<genType, genType_>(x), glsl::Common<genType, genType_>(y), glsl::Iota<genType, genType_>{});
}

template<typename genType>
inline auto abs(const genType& x) {
    return glsl::absolute(glsl::Common<genType>(x), glsl::Iota<genType>{});
}

template<typename genType>
inline auto ceil(const genType& x) {
    return glsl::ceiling(glsl::Common<genType>(x), glsl::Iota<genType>{});
}
template<typename genType>
inline auto floor(const genType& x) {
    return glsl::flooring(glsl::Common<genType>(x), glsl::Iota<genType>{});
}

template<typename genType>
inline auto fract(const genType& x) {
    return glsl::fraction(glsl::Common<genType>(x), glsl::Iota<genType>{});
}

template<typename genType>
inline auto round(const genType& x) {
    return glsl::rounder(glsl::Common<genType>(x), glsl::Iota<genType>{});
}

template<typename genType, typename genType_, typename = glsl::enable<glsl::broadcastable<genType, genType_>>>
inline auto mod(const genType& x, const genType_& y) {
    return glsl::modulus(glsl::Common<genType, genType_>(x), glsl::Common<genType, genType_>(y), glsl::Iota<genType, genType_>{});
}

template<typename genType, typename genType_, typename = glsl::enable<(1<glsl::Rows<genType> || (glsl::same<genType, float> && glsl::same<genType_, float>)) && glsl::Rows<genType> == glsl::Rows<genType_>&& glsl::broadcastable<genType, genType_>>>
inline auto pow(const genType& x, const genType_& y) {
    return glsl::power(glsl::Common<genType, genType_>(x), glsl::Common<genType, genType_>(y), glsl::Iota<genType, genType_>{});
}


template<typename genType, typename genType_, typename genType__, typename = glsl::enable<glsl::broadcastable<genType, genType_, genType__>>>
inline auto clamp(const genType& x, const genType_& minVal, const genType__& maxVal) {
    return glsl::clamper(glsl::Common<genType, genType_, genType__>(x), glsl::Common<genType, genType_, genType__>(minVal), glsl::Common<genType, genType_, genType__>(maxVal), glsl::Iota<genType, genType_, genType__>{});
}

template<typename genType, typename genType_, typename genType__, typename = glsl::enable<glsl::broadcastable<genType, genType_, genType__>>>
inline auto mix(const genType& x, const genType_& y, const genType__& a) {
    return glsl::mixer(glsl::Common<genType, genType_, genType__>(x), glsl::Common<genType, genType_, genType__>(y), glsl::Common<genType, genType_, genType__>(a), glsl::Iota<genType, genType_, genType__>{});
}


template<typename genType, typename genType_, typename genType__, typename = glsl::enable<glsl::broadcastable<genType, genType_, genType__>>>
inline auto smoothstep(const genType& edge0, const genType_& edge1, const genType__& x) {
    return glsl::smoothstepper(glsl::Common<genType, genType_, genType__>(edge0), glsl::Common<genType, genType_, genType__>(edge1), glsl::Common<genType, genType_, genType__>(x), glsl::Iota<genType, genType_, genType__>{});
}
template<typename genType, typename genType_, typename = glsl::enable<glsl::broadcastable<genType, genType_>>>
inline auto step(const genType& edge, const genType_& x) {
    return glsl::stepper(glsl::Common<genType, genType_>(edge), glsl::Common<genType, genType_>(x), glsl::Iota<genType, genType_>{});
}

template<typename genType>
inline auto sin(const genType& angle) {
    return glsl::sine(glsl::Common<genType>(angle), glsl::Iota<genType>{});
}

template<typename genType>
inline auto asin(const genType& angle) {
    return glsl::arcussine(glsl::Common<genType>(angle), glsl::Iota<genType>{});
}

template<typename genType>
inline auto cos(const genType& angle) {
    return glsl::cosine(glsl::Common<genType>(angle), glsl::Iota<genType>{});
}

template<typename genType>
inline auto acos(const genType& angle) {
    return glsl::arcuscosine(glsl::Common<genType>(angle), glsl::Iota<genType>{});
}

template<typename genType>
inline auto tan(const genType& angle) {
    return glsl::tangent(glsl::Common<genType>(angle), glsl::Iota<genType>{});
}

template<typename genType>
inline auto atan(const genType& y_over_x) {
    return glsl::arcustangent(glsl::Common<genType>(y_over_x), glsl::Iota<genType>{});
}

template<typename genType, typename genType_, typename = glsl::enable<glsl::broadcastable<genType, genType_>>>
inline auto atan(const genType& y, const genType_& x) {
    return glsl::arcustangent(glsl::Common<genType, genType_>(y), glsl::Common<genType, genType_>(x), glsl::Iota<genType, genType_>{});
}

template<typename genType>
inline auto degrees(const genType& radians) {
    return glsl::to_degrees(glsl::Common<genType>(radians), glsl::Iota<genType>{});
}

template<typename genType>
inline auto radians(const genType& degrees) {
    return glsl::to_radians(glsl::Common<genType>(degrees), glsl::Iota<genType>{});
}

inline vec3 cross(const vec3& x, const vec3& y) {
    return vec3(x.y * y.z - y.y * x.z, x.z * y.x - y.z * x.x, x.x * y.y - y.x * x.y);
}

inline float determinant(mat2 m) {
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}
inline float determinant(mat3 m) {
    return m[0][0] * determinant(mat2(m[1].yz, m[2].yz))
        - m[1][0] * determinant(mat2(m[0].yz, m[2].yz))
        + m[2][0] * determinant(mat2(m[0].yz, m[1].yz));
}
inline float determinant(mat4 m) {
    return m[0][0] * determinant(mat3(m[1].yzw, m[2].yzw, m[3].yzw))
        - m[1][0] * determinant(mat3(m[0].yzw, m[2].yzw, m[3].yzw))
        + m[2][0] * determinant(mat3(m[0].yzw, m[1].yzw, m[3].yzw))
        - m[3][0] * determinant(mat3(m[0].yzw, m[1].yzw, m[2].yzw));
}

inline mat2 inverse(mat2 m) {
    return mat2(m[1][1], -m[0][1], -m[1][0], m[0][0]) / (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
}
namespace glsl {
    inline vec2 givens_rotation(float f, float g) {
        bool swap = false;
        if (abs(f) < abs(g)) {
            float tmp = f;
            f = g;
            g = tmp;
            swap = true;
        }
        if (g == .0f)
            return vec2(copysignf(1.f, f), .0f);
        else {
            float t = g / f, u = copysignf(1.f, f) * sqrtf(1.f + t * t);
            vec2 result = vec2(1.f, t) / u;
            if (swap)
                result = result.yx;
            return result;
        }
    }
}
inline mat3 inverse(mat3 m) {
    mat3 result(1.f), rhs(1.f);
    for (int c = 0; c < 2; ++c) {
        for (int r = 2; r > c; --r) {
            mat3 rot(1.f);
            vec2 cs = glsl::givens_rotation(m[c][c], m[c][r]);
            rot[c][c] = rot[r][r] = cs.x;
            rot[c][r] = -(rot[r][c] = cs.y);
            m = rot * m;
            rhs = rot * rhs;
        }
    }
    for (int i = 0; i < 3; ++i) {
        result[i].z = rhs[i].z / m[2].z;
        rhs[i].xy -= result[i].z * m[2].xy;
        result[i].y = rhs[i].y / m[1].y;
        rhs[i].x -= result[i].y * m[1].x;
        result[i].x = rhs[i].x / m[0].x;
    }
    return result;
}
inline mat4 inverse(mat4 m) {
    mat4 result(1.f), rhs(1.f);
    for (int c = 0; c < 3; ++c) {
        for (int r = 3; r > c; --r) {
            mat4 rot(1.f);
            vec2 cs = glsl::givens_rotation(m[c][c], m[c][r]);
            rot[c][c] = rot[r][r] = cs.x;
            rot[c][r] = -(rot[r][c] = cs.y);
            m = rot * m;
            rhs = rot * rhs;
        }
    }
    for (int i = 0; i < 4; ++i) {
        result[i].w = rhs[i].w / m[3].w;
        rhs[i].xyz -= result[i].w * m[3].xyz;
        result[i].z = rhs[i].z / m[2].z;
        rhs[i].xy -= result[i].z * m[2].xy;
        result[i].y = rhs[i].y / m[1].y;
        rhs[i].x -= result[i].y * m[1].x;
        result[i].x = rhs[i].x / m[0].x;
    }
    return result;
}

template<int R, int C, typename F, int... I, typename = glsl::enable<(C>1)>>
        glsl::Matrix<C, R, F, I...> transpose(const glsl::Matrix<R, C, F, I...>& m) {
    glsl::Matrix<C, R, F, I...> result;
    ((result.data[I/R+(I%R)*C] = m.data[I]), ...);
    return result;
}


template<typename genType, typename genType_, typename = glsl::enable<glsl::broadcastable<genType, genType_>>>
inline auto dot(const genType& x, const genType_& y) {
    return glsl::dotter(glsl::Common<genType, genType_>(x), glsl::Common<genType, genType_>(y), glsl::Iota<genType, genType_>{});
}

template<typename genType>
inline auto length(const genType& x) {
    return glsl::len(glsl::Common<genType>(x), glsl::Iota<genType>{});
}
template<typename genType, typename genType_, typename = glsl::enable<glsl::broadcastable<genType, genType_>>>
inline auto distance(const genType& x, const genType_& y) {
    return glsl::len(glsl::Common<genType, genType_>(x-y), glsl::Iota<genType, genType_>{});
}
template<typename genType>
inline auto normalize(const genType& x) {
    return x / glsl::len(x, glsl::Iota<genType>{});
}

template<typename genType>
inline auto sqrt(const genType& x) {
    return glsl::square_root(glsl::Common<genType>(x), glsl::Iota<genType>{});
}

template<typename genType>
inline auto exp(const genType& x) {
    return glsl::exper(glsl::Common<genType>(x), glsl::Iota<genType>{});
}

template<typename genType>
inline auto exp2(const genType& x) {
    return glsl::exp2er(glsl::Common<genType>(x), glsl::Iota<genType>{});
}

template<typename genType>
inline auto log(const genType& x) {
    return glsl::loger(glsl::Common<genType>(x), glsl::Iota<genType>{});
}

template<typename genType>
inline auto log2(const genType& x) {
    return glsl::log2er(glsl::Common<genType>(x), glsl::Iota<genType>{});
}

template<typename genType>
inline auto sign(const genType& x) {
    return glsl::signum(glsl::Common<genType>(x), glsl::Iota<genType>{});
}

template<typename genType, typename genType_>
inline auto reflect(const genType& I, const genType_& N) {
    return I - 2 * dot(N, I) * N;
}

template<typename genType, typename genType_>
inline auto refract(const genType& I, const genType_& N, float eta) {
    glsl::Common<genType, genType_> R(.0f);
    float k = 1.0 - eta * eta * (1.0 - dot(N, I) * dot(N, I));
    if (k > 0.0)
        R = eta * I - (eta * dot(N, I) + sqrt(k)) * N;
    return R;
}

template<typename genType, typename = glsl::enable<glsl::same<glsl::Field<genType>, float>>>
inline auto floatBitsToInt(const genType& x) {
    return glsl::cast<int>(glsl::Common<genType>(x), glsl::Iota<genType>{});
}
template<typename genType, typename = glsl::enable<glsl::same<glsl::Field<genType>, float>>>
inline auto floatBitsToUint(const genType& x) {
    return glsl::cast<uint>(glsl::Common<genType>(x), glsl::Iota<genType>{});
}
template<typename genType, typename = glsl::enable<glsl::same<glsl::Field<genType>, int>>>
inline auto intBitsToFloat(const genType& x) {
    return glsl::cast<float>(glsl::Common<genType>(x), glsl::Iota<genType>{});
}
template<typename genType, typename = glsl::enable<glsl::same<glsl::Field<genType>, uint>>>
inline auto uintBitsToFloat(const genType& x) {
    return glsl::cast<float>(glsl::Common<genType>(x), glsl::Iota<genType>{});
}

template<typename genType, typename = glsl::enable<glsl::same<glsl::Field<genType>, double>>>
inline auto doubleBitsToInt(const genType& x) {
    return glsl::cast<int64_t>(glsl::Common<genType>(x), glsl::Iota<genType>{});
}
template<typename genType, typename = glsl::enable<glsl::same<glsl::Field<genType>, double>>>
inline auto doubleBitsToUint(const genType& x) {
    return glsl::cast<uint64_t>(glsl::Common<genType>(x), glsl::Iota<genType>{});
}
template<typename genType, typename = glsl::enable<glsl::same<glsl::Field<genType>, int64_t>>>
inline auto int64BitsToDouble(const genType& x) {
    return glsl::cast<double>(glsl::Common<genType>(x), glsl::Iota<genType>{});
}
template<typename genType, typename = glsl::enable<glsl::same<glsl::Field<genType>, uint64_t>>>
inline auto uint64BitsToDouble(const genType& x) {
    return glsl::cast<double>(glsl::Common<genType>(x), glsl::Iota<genType>{});
}

inline int64_t packInt2x32(ivec2 v) { return int64_t(v.y) << 32 | v.x; }
inline uint64_t packUint2x32(uvec2 v) { return uint64_t(v.y) << 32 | v.x; }

inline ivec2 unpackInt2x32(int64_t  v) { return ivec2(v, v>>32); }
inline uvec2 unpackUint2x32(uint64_t v) { return uvec2(v, v >> 32); }

inline int atomicAdd(int& mem, int data) { return 0; }
inline uint atomicAdd(uint& mem, uint data) { return 0u; }
inline int64_t atomicAdd(int64_t& mem, int64_t data) { return 0; }
inline uint64_t atomicAdd(uint64_t& mem, uint64_t data) { return 0; }

inline int atomicAnd(int& mem, int data) { return 0; }
inline uint atomicAnd(uint& mem, uint data) { return 0u; }
inline int64_t atomicAnd(int64_t& mem, int64_t data) { return 0; }
inline uint64_t atomicAnd(uint64_t& mem, uint64_t data) { return 0; }

inline int atomicCompSwap(int& mem, int comp, int data) { return 0; }
inline uint atomicCompSwap(uint& mem, uint comp, uint data) { return 0u; }
inline int64_t atomicCompSwap(int64_t& mem, int64_t comp, int64_t data) { return 0; }
inline uint64_t atomicCompSwap(uint64_t& mem, uint64_t comp, uint64_t data) { return 0; }

inline int atomicExchange(int& mem, int data) { return 0; }
inline uint atomicExchange(uint& mem, uint data) { return 0u; }
inline int64_t atomicExchange(int64_t& mem, int64_t data) { return 0; }
inline uint64_t atomicExchange(uint64_t& mem, uint64_t data) { return 0; }

inline int atomicMax(int& mem, int data) { return 0; }
inline uint atomicMax(uint& mem, uint data) { return 0u; }
inline int64_t atomicMax(int64_t& mem, int64_t data) { return 0; }
inline uint64_t atomicMax(uint64_t& mem, uint64_t data) { return 0; }

inline int atomicMin(int& mem, int data) { return 0; }
inline uint atomicMin(uint& mem, uint data) { return 0u; }
inline int64_t atomicMin(int64_t& mem, int64_t data) { return 0; }
inline uint64_t atomicMin(uint64_t& mem, uint64_t data) { return 0; }

inline int atomicOr(int& mem, int data) { return 0; }
inline uint atomicOr(uint& mem, uint data) { return 0u; }
inline int64_t atomicOr(int64_t& mem, int64_t data) { return 0; }
inline uint64_t atomicOr(uint64_t& mem, uint64_t data) { return 0; }

inline int atomicXor(int& mem, int data) { return 0; }
inline uint atomicXor(uint& mem, uint data) { return 0u; }
inline int64_t atomicXor(int64_t& mem, int64_t data) { return 0; }
inline uint64_t atomicXor(uint64_t& mem, uint64_t data) { return 0; }

inline void barrier() {}
inline void groupMemoryBarrier() {}
inline void memoryBarrier() {}
inline void memoryBarrierAtomicCounter() {}
inline void memoryBarrierBuffer() {}
inline void memoryBarrierImage() {}
inline void memoryBarrierShared() {}

inline const uvec3 gl_GlobalInvocationID = {};
inline const uvec3 gl_LocalInvocationID = {};
inline const uvec3 gl_WorkGroupSize = {};
inline const uvec3 gl_WorkGroupID = {};
inline const uvec3 gl_NumWorkGroups = {};
inline const uint gl_LocalInvocationIndex = 0u;

inline const vec4 gl_FragCoord = {};
inline const vec2 gl_PointCoord = {};
inline int gl_ViewportIndex;
inline const int gl_VertexID = 0;
inline const int gl_InstanceID = 0;
inline const int gl_InvocationID = 0;
inline int gl_PrimitiveIDIn;
inline const int gl_PrimitiveID = 0;
inline const int gl_PatchVerticesIn = 0;
inline const int gl_Layer = 0;

inline const vec3 gl_TessCoord = {};
inline float gl_TessLevelInner[2];
inline float gl_TessLevelOuter[4];

inline const bool gl_FrontFacing = true;
inline const bool gl_HelperInvocation = false;

inline vec4 gl_Position;
inline float gl_PointSize;
inline float gl_FragDepth;
inline float gl_ClipDistance[1];
inline float gl_CullDistance[1];
struct gl_PerVertex
{
  vec4 gl_Position;
  float gl_PointSize;
  float gl_ClipDistance[1];
} inline gl_in[1];

inline const int gl_NumSamples = 1;
inline const int gl_SampleID = 0;
inline int gl_SampleMask[1];
inline const int gl_SampleMaskIn[1] = { 0 };
inline const vec2 gl_SamplePosition = {};

template<typename genType> genType dFdx(genType p) { return p; }
template<typename genType> genType dFdy(genType p) { return p; }
template<typename genType> genType dFdxCoarse(genType p) { return p; }
template<typename genType> genType dFdyCoarse(genType p) { return p; }
template<typename genType> genType dFdxFine(genType p) { return p; }
template<typename genType> genType dFdyFine(genType p) { return p; }
template<typename genType> genType fwidth(genType p) { return p; }
template<typename genType> genType fwidthCoarse(genType p) { return p; }
template<typename genType> genType fwidthFine(genType p) { return p; }

// subgroup extension: see https://www.khronos.org/blog/vulkan-subgroup-tutorial

inline const uint gl_NumSubgroups = 1, gl_SubgroupID = 0, gl_SubgroupSize = 128, gl_SubgroupInvocationID = 0;
inline const uvec4 gl_SubgroupEqMask{ 0 }, gl_SubgroupGeMask{ 0 }, gl_SubgroupGtMask{ 0 }, gl_SubgroupLeMask{ 0 }, gl_SubgroupLtMask{ 0 };
inline void subgroupBarrier() {}
inline void subgroupMemoryBarrier() {}
inline void subgroupMemoryBarrierBuffer() {}
inline void subgroupMemoryBarrierShared() {}
inline void subgroupMemoryBarrierImage() {}
inline bool subgroupElect() { return false; }

inline bool subgroupAll(bool value) { return value; }
inline bool subgroupAny(bool value) { return value; }
template<typename T> bool subgroupAllEqual(T value) { (void)value; return false; }

template<typename T> T subgroupBroadcast(T value, uint id) { (void)id; return value; }
template<typename T> T subgroupBroadcastFirst(T value) { return value; }
inline uvec4 subgroupBallot(bool value) { (void)value; return uvec4(0); }
inline bool subgroupInverseBallot(uvec4 value) { (void)value; return false; }
inline bool subgroupBallotBitExtract(uvec4 value, uint index) { (void)value; (void)index; return false; }
inline uint subgroupBallotBitCount(uvec4 value) { (void)value; return 0; }
inline uint subgroupBallotInclusiveBitCount(uvec4 value) { (void)value; return 0; }
inline uint subgroupBallotExclusiveBitCount(uvec4 value) { (void)value; return 0; }
inline uint subgroupBallotFindLSB(uvec4 value) { (void)value; return 0; }
inline uint subgroupBallotFindMSB(uvec4 value) { (void)value; return 0; }

template<typename T> T subgroupAdd(T value) { return value; }
template<typename T> T subgroupMul(T value) { return value; }
template<typename T> T subgroupMin(T value) { return value; }
template<typename T> T subgroupMax(T value) { return value; }
template<typename T> T subgroupAnd(T value) { return value; }
template<typename T> T subgroupOr(T value) { return value; }
template<typename T> T subgroupXor(T value) { return value; }

template<typename T> T subgroupInclusiveAdd(T value) { return value; }
template<typename T> T subgroupInclusiveMul(T value) { return value; }
template<typename T> T subgroupInclusiveMin(T value) { return value; }
template<typename T> T subgroupInclusiveMax(T value) { return value; }
template<typename T> T subgroupInclusiveAnd(T value) { return value; }
template<typename T> T subgroupInclusiveOr(T value) { return value; }
template<typename T> T subgroupInclusiveXor(T value) { return value; }

template<typename T> T subgroupExclusiveAdd(T value) { return value; }
template<typename T> T subgroupExclusiveMul(T value) { return value; }
template<typename T> T subgroupExclusiveMin(T value) { return value; }
template<typename T> T subgroupExclusiveMax(T value) { return value; }
template<typename T> T subgroupExclusiveAnd(T value) { return value; }
template<typename T> T subgroupExclusiveOr(T value) { return value; }
template<typename T> T subgroupExclusiveXor(T value) { return value; }

template<typename T> T subgroupShuffle(T value, uint index) { (void)index; return value; }
template<typename T> T subgroupShuffleXor(T value, uint mask) { (void)mask; return value; }
template<typename T> T subgroupShuffleUp(T value, uint delta) { (void)delta; return value; }
template<typename T> T subgroupShuffleDown(T value, uint delta) { (void)delta; return value; }

template<typename T> T subgroupClusteredAdd(T value, uint clusterSize) { (void)clusterSize; return value; }
template<typename T> T subgroupClusteredMul(T value, uint clusterSize) { (void)clusterSize; return value; }
template<typename T> T subgroupClusteredMin(T value, uint clusterSize) { (void)clusterSize; return value; }
template<typename T> T subgroupClusteredMax(T value, uint clusterSize) { (void)clusterSize; return value; }
template<typename T> T subgroupClusteredAnd(T value, uint clusterSize) { (void)clusterSize; return value; }
template<typename T> T subgroupClusteredOr(T value, uint clusterSize) { (void)clusterSize; return value; }
template<typename T> T subgroupClusteredXor(T value, uint clusterSize) { (void)clusterSize; return value; }

template<typename T> T subgroupQuadBroadcast(T value, uint id) { (void)id; return value; }
template<typename T> T subgroupQuadSwapHorizontal(T value) { return value; }
template<typename T> T subgroupQuadSwapVertical(T value) { return value; }
template<typename T> T subgroupQuadSwapDiagonal(T value) { return value; }


// missing: hyperbolic trigonometry, faceforward etc geometric functions.
