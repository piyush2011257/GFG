/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-168/

Given an array of integers, find a subset of numbers from this array such that, after negating the elements of this set, the total sum of all elements would be equal to zero.

http://www.careercup.com/question?id=5096672887570432
For given set of natural number, suppose we can negate some number. Find what all number we should negate such that sum of all number (after negating some number) is zero. For ex: {1,2,3} return {-1, -2}, {1,2,3,4} return {-1,-4} or {-2,-3}. 1st check if such number in given set exist or not. If not return empty array else return numbers.

f you sum all the numbers in the set, then you just have to find the numbers which total half of that sum (i.e if you have 1,2,3,4 sum is 10. 2 + 3 total 5, 1 + 4 totals 5).

Say you get that the sum of your set divided by two is S.
At this point, you just gotta use the 0/1 knapsack algorithm (can't repeat elements) to find a combination of numbers that sums up to that S.
This would be O(nS) complexity which is exponential (since usually any N numbers will sum up higher than 2N).

Func(S,N)= func(S,N-1) || func(S-val(i),N-1)
if ( S == 0 )
	return 1;
if N==-1 || S < 0 
	return 0;
*/

#include<cstdio>
using namespace std;

const int len=5;

int main()
{	int a[len]={2,2,3,4,5};
	int sum=0;
	for ( int i=0; i<len; i++ )
		sum += a[i];
	if ( sum % 2 != 0 )
	{	printf("Odd sum!!\n");
		return 0;
	}
	sum=sum/2;			// if sum is odd, then it can'd be done	
	int func[len][sum+1];
	for ( int i=0; i<len; i++ )
		for ( int j=1; j<=sum; j++ )
			func[i][j]=0;
	for ( int i=0; i<len; i++ )
		func[i][0]=1;
	for ( int i=a[0], j=0; i<=sum; i+=a[0], j++ )
		func[0][i]=1;
	for ( int i=1; i<len; i++ )
	{	for ( int j=1; j<=sum; j++ )
		{	bool m1=0, m2=0;
			if ( j-a[i] >= 0 )
				m1=func[i-1][j-a[i]];
			m2=func[i-1][j];
			func[i][j]=m1||m2;
		}
	}
	printf("%d\n",func[len-1][sum]);
	for ( int i=0; i<len; i++ )
	{	for ( int j=0; j<=sum; j++ )
			printf("%d ", func[i][j]);
		printf("\n");
	}
	// we can trace back the ordering on the basis of func(i-1,N) and func(i-1,N-val(i)), whichever is 1
	return 0;
}
