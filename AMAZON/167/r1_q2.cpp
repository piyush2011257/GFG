/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-167-sde-1-year-6-months-experience

Given two rectangles, find if the given two rectangles overlap or not
http://www.geeksforgeeks.org/find-two-rectangles-overlap/

Non-Overlap cases

x1,y1		x2,y1
x1,y2		x2,y2

thus we need only x1,y1 and x2,y2 to define a rectangle

+---------+	+--------+
|	  |	|	 |
|	  |	|	 |
+---------+	+--------+

Either on left or right
x1' > x2
or 
x2' > x1

+-------+
|	|
|	|
+-------+

+-------+
|	|
|	|
+-------+

Or up or down

y1 > y2'
or
y2' > y1


Else overlap in any form
*/
#include<stdio.h>
 
struct Point
{	int x, y;	};
 
bool doOverlap(Point l1, Point r1, Point l2, Point r2)
{	if (l1.x > r2.x || l2.x > r1.x)
        	return 0;
    	if (l1.y < r2.y || l2.y < r1.y)
        	return 0;
    	return 1;
}
 
int main()
{	Point l1 = {0, 10}, r1 = {10, 0};
    	Point l2 = {5, 5}, r2 = {15, 0};
    	if (doOverlap(l1, r1, l2, r2))
        	printf("Rectangles Overlap");
    	else
        	printf("Rectangles Don't Overlap");
    	return 0;
}
