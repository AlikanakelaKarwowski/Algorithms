# Algorithms Project 3 #

-----

# **READ ME FIRST** #

-----

* The zipped file contains 6 files labeled *main.cpp*, *seamCarve.hpp*, *seamCarve.cpp*, *README.md*, *testcases.doc* and *Makefile*.

-----

## main.cpp ##

* To run the program, in a terminal type `make`
* Once it is done type `./carve file.pgm vSeams hSeams`
* This will create a file called `file_processed.pgm`
* This file is the .pgm file that had the seams carved.

-----

* Type `make clean` to clean up compilation objects like .obj files or .o files.

-----

## What This Program Does: ##

* This program carves vertical and horizontal seams from a .pgm file using dynamic programming.

-----
* There were not any special or specific algorithms used, but dynamic programming was used to carve the seams.
* Dynamic programming follows a few steps:
    * Define the problem recursively
    * Design a solution to work from bottom to top
* This is how I made this program
