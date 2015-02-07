/*
http://www.geeksforgeeks.org/dynamic-programming-set-13-cutting-a-rod/

Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

The problem looks similar to unbounded knapsack, however, there is a subtle difference
In case of knapsack , it is not necessary to fill the bag and some unutilized space's value is NOT added in the final value.
However, here in this case we have prices for each value less than N and hence there no such thing as piece being wasted and all pieces will have the value added

Hence, for unbounded knapsack
f(C)= max {	f(C-1),					for empty space considerations
	    	for i=1 -> N f(C-size[i])
	  }

But for cutting rod
f(C)= max { ( for i=1 -> N ) f(C-size[i]) }
	We can still add f(C-1) but that wont make an effect since the lost size of 1 will have value of 1 added. No empty space / waste in this case
*/

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int cut_rod (int *size, int *val, int n );

int main()
{	int n;
	cin>>n;
	int a[n], val[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i]>>val[i];
	cout<<"max val: "<<cut_rod(a,val,n)<<endl;
	return 0;
}

int cut_rod (int *size, int *val, int n )
{	int func[n+1], max;
	memset(func,0,sizeof(func));
	for ( int i=1; i<=n; i++ )
	{	max=0;
		for ( int j=0; j<n; j++ )
		{	if ( i-size[j] >= 0 )
			{	//cout<<j<<" "<<val[j]<<endl;
				if ( val[j] + func[i-size[j]] > max )
					max=val[j] + func[i-size[j]];
			}
		}
		//printf("\n");
		func[i]=max;
	}
	for ( int i=1; i<=n; i++ )
		cout<<func[i]<<" ";
	cout<<endl;
	return func[n];
}
