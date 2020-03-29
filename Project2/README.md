# Algorithms Project 2 #

# **PLEASE READ ME FIRST** #

* The zipped file contains 4 files labeled *convexHull435.cpp*, *ConvexHull_GUI.java*, *Makefile*, *README.md* and a folder labeled *output*

* **Do not modify these files or folders unless you want to run them using your own makefile**

## convexHull435.cpp: ##

* To run the program, in a terminal type `make`
* Once it is done type `make generate`
* Then type `make runJ`, `make runG`, `make runQ`, or `make runAll` to run the program with the appropriate Algorithm.
* It may take a while to run **ALL** the datasets for an Algorithm but please be patient.

* The program should generate a file for each datafile in the *output/[Algorithm]/* folder that shows the time it took to run the algorithm on specific types of data sets.
* These files are called *test_[Algorithm]_[Data File Name].txt*

* To test that the algorithms worked correctly, you can type `make testJ`, `make testG`, or `make testQ` to have the java GUI run on the 10 and 1 million point files of each type.
* **Note:** you may need to run the GUI through *xterminal* or with an *x server* running with proper setups to display the GUI

* Type `make clean` to clean up compilation objects like .obj files or .o files.
* Type `make cleanTest` to clean up all the test files located in the *output/[Algorithm]/* folder.
* Type `make cleanAll` to clean up all the data files and outputfiles from running the algorithms and compilation
