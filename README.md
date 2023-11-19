# shell texturing

This is my entry to Acerola's shell texturing challenge. I implemented the basic algorithm and shaded it to look like grass. Then I added some variation to the base shape of the grass and animated it like there's gusts of wind blowing. Both of these tweaks use the same underlying principle to change the shape; instead of moving the mesh around and keeping the geometry fixed to it (as monsieur Lagrange would view the world), we keep the mesh fixed and move the geometry "under it" (as herr Euler would have it). A simple version of this would just be to animate the UVs, but I do it in 3D to get some relatively not-horrible bending going on.

The code is all in `main.cpp`, it's written using my ssgl framework (there's a bunch of examples and stuff in the master branch should you want to see that).

A short demo is available at https://youtu.be/dUqhqGNbPHE
