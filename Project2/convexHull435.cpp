// Alex Karwowski
// akk42@zips.uakron.edu
// Algorithms Project 2


// You need to complete this program for your project.
// Standard libraries

// DISCLAIMER: all of the code besides the main driver function was taken from:
// https://www.geeksforgeeks.org/quickhull-algorithm-convex-hull/
// https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/
// https://www.geeksforgeeks.org/convex-hull-set-2-graham-scan/
// and was used with permission from Prof. Duan.

#include <stack>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

// Create a point structure to store x and y values in.
struct Point
{
	int x, y;
};

// Stores the result (points of convex hull)
// Use a set to make sure duplicate values are ommited
std::set<Point> hull;

// Jarvis March Functions //
int jOrientation(Point p, Point q, Point r);
void jConvexHull(std::vector<Point> points, int n, std::ofstream &output);

// Graham Scan Functions //
Point gNextToTop(std::stack<Point> &S);
void gSwap(Point &p1, Point &p2);
int gDistSq(Point p1, Point p2);
int gOrientation(Point p, Point q, Point r);
int gCompare(const void *vp1, const void *vp2);
void gConvexHull(Point points[], int n, std::ofstream &output);

// Quick Hull Functions //
int qFindSide(Point p1, Point p2, Point p);
int qLineDist(Point p1, Point p2, Point p);
void qHull(Point a[], int n, Point p1, Point p2, int side);
void qPrintHull(Point a[], int n, std::vector<Point>& convexHull, std::ofstream &output);


int main(int argc, char *argv[])
{
    if (argc < 3)
        std::cout << "wrong format! should be \"a.exe algType dataFile\"";
    else
    {
        // Argument 1 used to determine Algorithm Type to use
        std::string algType = argv[1];
        // Argument 2 used to determine the filename to open
        std::string dataFilename = argv[2];

        std::string outputFile = "";
        std::ifstream dataFile;

        // Read data points from dataFile
        dataFile.open(dataFilename);

        // Use a switch statement because it is cleaner to look at
        switch(algType[0])
        {
            case 'G':
                {
                    //call your Graham Scan algorithm to solve the problem
                    Point tmp;
                    std::vector<Point> points;
                    int n=0, x=0, y=0;

                    // Read data points from file and store them as points in a vector
                    while(dataFile >> tmp.x >> tmp.y)
                        {
                            points.push_back(tmp);
                            ++n;
                        }

                    // NOTE: I could not get Graham scan to work with a vector so
                    // This code takes the vectors elements and puts them in a pointer array.
                    int vSize = points.size();
                    Point *aPoints = new Point [vSize];
                    for(int i = 0; i < vSize; ++i)
                        aPoints[i] = points[i];

                    // Create an output file which is in the format "hull_G_" + (File Name)
                    outputFile = "hull_G_" + dataFilename;
                    std::ofstream hullFile(outputFile);

                    // Run Graham Scan 10 times to get better runtime results
                    for (int i = 1; i < 10; i++)
                        gConvexHull(aPoints, n, hullFile);
                    hullFile.close();
                    break;
                }
            case 'J':
                {
                    //call your Javis March algorithm to solve the problem
                    Point tmp;
                    std::vector<Point> points;
                    int n=0, x=0, y=0;

                    // Read data points from file and store them as points in a vector
                    while(dataFile >> tmp.x >> tmp.y)
                        {
                            points.push_back(tmp);
                            ++n;
                        }

                    // Create an output file which is in the format "hull_J_" + (File Name)
                    outputFile = "hull_J_" + dataFilename;
                    std::ofstream hullFile(outputFile);

                    // Run Jarvis March 10 times to get better runtime results
                    for (int i = 0; i <10; ++i)
                        jConvexHull(points, n, hullFile);

                    hullFile.close();
                    break;
                }
            case 'Q':
                {
                    //call your Quickhull algorithm to solve the problem
                    Point tmp;
                    std::vector<Point> points, cHull;
                    int n=0, x=0, y=0;

                    // Read data points from file and store them as points in a vector
                    while(dataFile >> tmp.x >> tmp.y)
                        {
                            points.push_back(tmp);
                            ++n;
                        }

                    // NOTE: I could not get Quickhull to work with a vector so
                    // This code takes the vectors elements and puts them in a pointer array.
                    int vSize = points.size();
                    Point *aPoints = new Point [vSize];
                    for(int i = 0; i < vSize; ++i)
                        aPoints[i] = points[i];

                    // Create an output file which is in the format "hull_Q_" + (File Name)
                    outputFile = "hull_Q_" + dataFilename;
                    std::ofstream hullFile(outputFile);

                    // Run Quick Hull 10 times to get a better runtime result
                    for (int i = 0; i <10; ++i)
                        qPrintHull(aPoints, n, cHull, hullFile);

                    hullFile.close();
                    break;
                }
            default:
                // any other parameter is called
                // see the Key & Peele Skit Substitute Teacher for reference
                // https://www.youtube.com/watch?v=Dd7FixvoKBw
                std::cout << "You done messed up TA" << std::endl;
                break;
        }
        //you should be able to visulize your convex hull using the "ConvexHull_GUI" program.
        dataFile.close();
    }

    return 0;
}

/*////////////////////////////////////////////////////////////*/
/*                      JARVIS MARCH                          */
/*////////////////////////////////////////////////////////////*/

// A C++ program to find convex hull of a set of points. Refer
// https://www.geeksforgeeks.org/orientation-3-ordered-points/
// for explanation of orientation()

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int jOrientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; // colinear
	return (val > 0)? 1: 2; // clock or counterclock wise
}

// Prints convex hull of a set of n points.
void jConvexHull(std::vector<Point> points, int n, std::ofstream &output)
{
	// There must be at least 3 points
	if (n < 3)
        return;

	// Initialize Result
	std::vector<Point> hull;

	// Find the leftmost point
	int l = 0;
	for (int i = 1; i < n; i++)
		if (points[i].x < points[l].x)
			l = i;

	// Start from leftmost point, keep moving counterclockwise
	// until reach the start point again. This loop runs O(h)
	// times where h is number of points in result or output.
	int p = l, q;
	do
	{
		// Add current point to result
		hull.push_back(points[p]);

		// Search for a point 'q' such that orientation(p, x,
		// q) is counterclockwise for all points 'x'. The idea
		// is to keep track of last visited most counterclock-
		// wise point in q. If any point 'i' is more counterclock-
		// wise than q, then update q.
		q = (p+1)%n;
		for (int i = 0; i < n; i++)
		{
		// If i is more counterclockwise than current q, then
		// update q
		if (jOrientation(points[p], points[i], points[q]) == 2)
			q = i;
		}

		// Now q is the most counterclockwise with respect to p
		// Set p as q for next iteration, so that q is added to
		// result 'hull'
		p = q;

	} while (p != l); // While we don't come to x point

	// Print Result
	for (int i = 0; i < hull.size(); i++)
		output << hull[i].x << '\t' << hull[i].y << '\n';
}

/*////////////////////////////////////////////////////////////*/
/*                      End of JARVIS MARCH                   */
/*////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////*/
/*                      Graham Scan                           */
/*////////////////////////////////////////////////////////////*/
// A C++ program to find convex hull of a set of points. Refer
// https://www.geeksforgeeks.org/orientation-3-ordered-points/
// for explanation of orientation()

// A global point needed for sorting points with reference
// to the x point Used in compare function of qsort()
Point p0;

// A utility function to find next to top in a stack
Point gNextToTop(std::stack<Point> &S)
{
	Point p = S.top();
	S.pop();
	Point res = S.top();
	S.push(p);
	return res;
}

// A utility function to swap two points
void gSwap(Point &p1, Point &p2)
{
	Point temp = p1;
	p1 = p2;
	p2 = temp;
}

// A utility function to return square of distance
// between p1 and p2
int gDistSq(Point p1, Point p2)
{
	return (p1.x - p2.x)*(p1.x - p2.x) +
		(p1.y - p2.y)*(p1.y - p2.y);
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int gOrientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; // colinear
	return (val > 0)? 1: 2; // clock or counterclock wise
}

// A function used by library function qsort() to sort an array of
// points with respect to the x point
int gCompare(const void *vp1, const void *vp2)
{
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    // Find orientation
    int o = gOrientation(p0, *p1, *p2);
    if (o == 0)
    	return (gDistSq(p0, *p2) >= gDistSq(p0, *p1))? -1 : 1;

    return (o == 2)? -1: 1;
}

// Prints convex hull of a set of n points.
void gConvexHull(Point points[], int n, std::ofstream &output)
{
    // Find the bottommost point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
    	int y = points[i].y;

    	// Pick the bottom-most or chose the left
    	// most point in case of tie
    	if ((y < ymin) || (ymin == y &&
    		points[i].x < points[min].x))
    		ymin = points[i].y, min = i;
    }

    // Place the bottom-most point at x position
    gSwap(points[0], points[min]);

    // Sort n-1 points with respect to the x point.
    // A point p1 comes before p2 in sorted output if p2
    // has larger polar angle (in counterclockwise
    // direction) than p1
    p0 = points[0];
    qsort(&points[1], n-1, sizeof(Point), gCompare);

    // If two or more points make same angle with p0,
    // Remove all but the one that is farthest from p0
    // Remember that, in above sorting, our criteria was
    // to keep the farthest point at the end when more than
    // one points have same angle.
    int m = 1; // Initialize size of modified array
    for (int i=1; i<n; i++)
    {
    	// Keep removing i while angle of i and i+1 is same
    	// with respect to p0
    	while (i < n-1 && gOrientation(p0, points[i],
    									points[i+1]) == 0)
    		i++;


    	points[m] = points[i];
    	m++; // Update size of modified array
    }

    // If modified array of points has less than 3 points,
    // convex hull is not possible
    if (m < 3) return;

    // Create an empty stack and push x three points
    // to it.
    std::stack<Point> S; ;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    // Process remaining n-3 points
    for (int i = 3; i < m; i++)
    {
    	// Keep removing top while the angle formed by
    	// points next-to-top, top, and points[i] makes
    	// a non-left turn
        while (gOrientation(gNextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
    }

    // Now stack has the output points, print contents of stack
    while (!S.empty())
    {
    	Point p = S.top();
    	output << p.x << '\t' << p.y << std::endl;
    	S.pop();
    }
}

/*////////////////////////////////////////////////////////////*/
/*                    End of Graham Scan                      */
/*////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////*/
/*                       Quickhull                            */
/*////////////////////////////////////////////////////////////*/
// C++ program to implement Quick Hull algorithm
// to find convex hull.
//using namespace std;

// Returns the side of point p with respect to line
// joining points p1 and p2.
int qFindSide(Point p1, Point p2, Point p)
{
	int val = (p.y - p1.y) * (p2.x - p1.x) -
			(p2.y - p1.y) * (p.x - p1.x);

	if (val > 0)
		return 1;
	if (val < 0)
		return -1;
	return 0;
}

// returns a value proportional to the distance
// between the point p and the line joining the
// points p1 and p2
int qLineDist(Point p1, Point p2, Point p)
{
	return abs ((p.y - p1.y) * (p2.x - p1.x) -
			(p2.y - p1.y) * (p.x - p1.x));
}

// End points of line L are p1 and p2.  side can have value
// 1 or -1 specifying each of the parts made by the line L
void qHull(Point points[], int n, const Point& point1, const Point& point2, int side,
               std::vector<Point>& convexHull)
{
    int ind = -1;
    int max_dist = 0;
    // finding the point with maximum distance
    // from L and also on the specified side of L.
    for (int i = 0; i < n; i++)
    {
        int temp = qLineDist(point1, point2, points[i]);
        if (qFindSide(point1, point2, points[i]) == side && temp > max_dist)
        {
            ind = i;
            max_dist = temp;
        }
    }

    // If no point is found, add the end points
    // of L to the convex hull.
    if (ind == -1)
    {
        convexHull.push_back(point1);
        convexHull.push_back(point2);
        return;
    }

    // Recur for the two parts divided by a[ind]
    qHull(points, n, points[ind], point1, -qFindSide(points[ind], point1, point2), convexHull);
    qHull(points, n, points[ind], point2, -qFindSide(points[ind], point2, point1), convexHull);

}

void qPrintHull(Point points[], int n, std::vector<Point>& convexHull, std::ofstream &output)
{
    // a[i].y -> y-coordinate of the ith point
    if (n < 3)
    {
        std::cout << "Convex hull not possible\n";
        return;
    }

    // Finding the point with minimum and
    // maximum x-coordinate
    int min_x = 0, max_x = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].x < points[min_x].x)
            min_x = i;
        if (points[i].y > points[max_x].y)
            max_x = i;
    }

    // Recursively find convex hull points on
    // one side of line joining a[min_x] and
    // a[max_x].

    qHull(points, n, points[min_x], points[max_x], 1, convexHull);

    // Recursively find convex hull points on
    // other side of line joining a[min_x] and
    // a[max_x]

    qHull(points, n, points[min_x], points[max_x], -1, convexHull);

    // copy vector into an array
    int hsize = convexHull.size();
    Point arrayHull[hsize];
    for (size_t i = 0; i < hsize; ++i)
    {
        arrayHull[i].x = convexHull[i].x;
        arrayHull[i].y = convexHull[i].y;
    }

    // find lowest point
    int ymin = arrayHull[0].y, min = 0;
    for (int i = 1; i < hsize; i++)
    {
        int yVal = arrayHull[i].y;

        // Pick the bottom-most or chose the left
        // most point in case of tie
        if ((yVal < ymin) || (ymin == yVal &&
            arrayHull[i].x < arrayHull[min].x))
            ymin = arrayHull[i].y, min = i;
    }

    // Place the bottom-most point at x position
    std::swap(arrayHull[0], arrayHull[min]);

    p0 = arrayHull[0];
    qsort(&arrayHull[1], hsize - 1, sizeof(Point), gCompare);

    // Print Result
    for (size_t i = 0; i < hsize; ++i)
    {
        output << arrayHull[i].x << '\t' << arrayHull[i].y << '\n';
    }
}

/*////////////////////////////////////////////////////////////*/
/*                    End of Quickhull                        */
/*////////////////////////////////////////////////////////////*/
