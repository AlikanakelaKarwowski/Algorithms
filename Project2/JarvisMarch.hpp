#ifndef JARVISMARCH_HPP_INCLUDED
#define JARVISMARCH_HPP_INCLUDED

#include <vector>
#include <iostream>
#include <fstream>
struct Point
{
    int x, y;
};

class Jarvis
{
    public:
        //find orientation of ordered triplet
        int orientation(Point p, Point q, Point r);

        //prints convex hull of a set of n points
        void convexHull(std::vector<Point> points, int n, std::ofstream &output);

        //point structure


};

#endif
