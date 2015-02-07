/*
http://www.geeksforgeeks.org/snapdeal-interview-experience-set-6-campus/
Given points of two lines A(x1,y1 x2,y2) & B(x3,y3 x4,y4) find whether the points intersect or not!

http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=geometry2
*/

#include<cstdio>
#include<iostream>
using namespace std;

inline int min ( double x, double y )
{	return x<y ? x : y;	}

inline int max ( double x, double y )
{       return x>y ? x : y;     }

void eval ( int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4 );

int main()
{	int x1,y1,x2,y2,x3,y3,x4,y4;
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	eval(x1,x2,x3,x4,y1,y2,y3,y4);
	return 0;
}

void eval ( int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4 )
{	int A1=y2-y1;
	int B1=x1-x2;
	int C1=A1*x1 + B1*y1;
	int A2=y4-y3;
        int B2=x3-x4;
        int C2=A2*x3 + B2*y3;
	int det= A1*B2 - A2*B1;
	if ( det == 0 )
	{	cout<<"Parallel lines"<<endl;
		return;
	}
	double x,y;
	x=(B2*C1 - B1*C2)/det;
	y=(- A2*C1 + A1*C2)/det;
	printf("Intersection point of lines : %f %f\n",x,y);
	// to check if intersection of segments
	if ( min(x1,x2) <= x && x <= max(x2,x1) && min(y1,y2) <= y && y <= max(y2,y1) )		// intersection point lies in segment region
		printf("Yes\n");
	else
		printf("No\n");
	return;
}
