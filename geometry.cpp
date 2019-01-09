/*
 Given a triangle and a point, your task is to check whether the point lies completely inside the triangle or not.

You will be give three points p1, p2, p3 denoting the vertices of the triangle. Also a point x will be provided denoting the test point.

Fill in the function bool is_inside_triangle(Point p1, Point p2, Point p3, Point x)

which returns true iff the point x lies completely inside the triangle formed by p1, p2, p3.

Note: It is guaranteed that p1, p2, p3 form a valid triangle with non-zero area. Also the x & y coordinate of all the points are integers.

Note: Point is a structure, whose definition is provided in student.cpp

The Point structure is defined as follows. You can make use of it in your code.

struct Point{

 int x;

 int y;

 Point(int a, int b) : x(a), y(b) {}

};
*/
// Don't remove the next line
#include "point.h"
#include <stdlib.h>

// create extra functions here
float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

bool is_inside_triangle(Point p1, Point p2, Point p3, Point p4)
{
    float A = area (p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    float A1 = area (p4.x, p4.y, p2.x, p2.y, p3.x, p3.y);

   /* Calculate area of triangle PAC */
   float A2 = area (p1.x, p1.y, p4.x, p4.y, p3.x, p3.y);

   /* Calculate area of triangle PAB */
   float A3 = area (p1.x, p1.y, p2.x, p2.y, p4.x, p4.y);

   /* Check if sum of A1, A2 and A3 is same as A */
   return   (A == A1 + A2 + A3);

    // fill in your code here

}

