# Algorithms Project 2 #

-----

# **READ ME FIRST** #

-----

* The zipped file contains 5 files labeled *convexHull435.cpp*, *ConvexHull_GUI.java*, *Makefile*, *README.md*, *Algo_Project_2.xlsx* and a folder labeled *output*

* **Do not modify these files or folders unless you want to run them using your own makefile**

-----

## convexHull435.cpp: ##

* To run the program, in a terminal type `make`
* Once it is done type `make generate`
* Then type `make runJ`, `make runG`, `make runQ`, or `make runAll` to run the program with the appropriate Algorithm.
* It may take a while to run **ALL** the datasets for an Algorithm but please be patient.

-----

* The program should generate a file for each datafile in the *output/[Algorithm]/* folder that shows the time it took to run the algorithm on specific types of data sets.
* These files are called *test_[Algorithm]_[Data File Name].txt*

-----

* To test that the algorithms worked correctly, you can type `make testJ`, `make testG`, or `make testQ` to have the java GUI run on the 10 and 1 million point files of each type.
* **Note:** you may need to run the GUI through *xterminal* or with an *x server* running with proper setups to display the GUI

-----

* Type `make clean` to clean up compilation objects like .obj files or .o files.
* Type `make cleanTest` to clean up all the test files located in the *output/[Algorithm]/* folder.
* Type `make cleanAll` to clean up all the data files and outputfiles from running the algorithms and compilation

-----

## What This Program Does: ##

* This program generates a convex hull out of a set of points given. There are 3 algorithms that are used to generate the convex hull, **Graham Scan**, **Jarvis March**, and **Quick Hull**.

-----

* **Graham Scan:** is a method of finding the convex hull of a set of points with time complexity **O(n*log(n))**.

    * The first step in this algorithm is to find the point with the lowest y-coordinate. If there are 2 or more points with the same y-coordinate the point with the lowest x-coordinate should be chosen. Call this point P.

    * Next, the set of points must be sorted in increasing order of the angle they and the point P make with the x-axis.

    * The algorithm proceeds by considering each of the points in the sorted array in sequence. For each point, it is first determined whether traveling from the two points immediately preceding this point constitutes making a left turn or a right turn. (Wikipedia)

    * If a right turn, the second-to-last point is not part of the convex hull, and lies 'inside' it. The same determination is then made for the set of the latest point and the two points that immediately precede the point found to have been inside the hull, and is repeated until a "left turn" set is encountered, at which point the algorithm moves on to the next point in the set of points in the sorted array minus any points that were found to be inside the hull; there is no need to consider these points again. (Wikipedia)

    * If a left turn, the algorithm adds the point to the set, and moves on until it either reaches the starting point or it reaches a right turn.

    * Once it reaches the starting point it is finished.

-----

* **Jarvis March:** is a method of finding the convex hull of a set of points with time complexity **O(n*h)**, where n is the number of points and h is the number of points on the convex hull.

    * Jarvis March Algorithm begins with i=0 and a point P(0) known to be on the convex hull, e.g., the leftmost point, and selects the point P(i+1) such that all points are to the right of the line P(i) and P(i+1). (Wikipedia)

    * This point may be found in O(n) time by comparing polar angles of all points with respect to point pi taken for the center of polar coordinates. (Wikipedia)

    * Letting i=i+1, and repeating until one reaches P(h)= P(0) again yields the convex hull in *h* steps. (Wikipedia)

    * In two dimensions, the gift wrapping algorithm is similar to the process of winding a string (or wrapping paper) around the set of points. (Wikipedia)

-----

* **Quick Hull:**  is a method of computing the convex hull of a set of points. It uses a divide and conquer approach similar to that of quicksort. Its worst case complexity **O(n^2)**, with an best case of **O(n*log(n))**.

    * Find the points with minimum and maximum x coordinates, as these will always be part of the convex hull. If many points with the same minimum/maximum x exist, use ones with minimum/maximum y correspondingly. (Wikipedia)

    * Use the line formed by the two points to divide the set in two subsets of points, which will be processed recursively. (Wikipedia)

    * Determine the point, on one side of the line, with the maximum distance from the line. This point forms a triangle with those of the line. (Wikipedia)

    * The points lying inside of that triangle cannot be part of the convex hull and can therefore be ignored in the next steps. (Wikipedia)

    * Repeat the previous two steps on the two lines formed by the triangle (not the initial line). (Wikipedia)

    * Keep on doing so on until no more points are left, the recursion has come to an end. Then merge all halves together to get the composite convex hull.
