/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-170/
Design a system which would make a schedule for a user to complete a book in given number of days. A pre condition is that the schedule for every day should end at the end of some chapter.

http://cs.stackexchange.com/questions/19181/partition-array-into-k-subsets-each-with-balanced-sum
http://www.geeksforgeeks.org/optimal-read-list-given-number-days/
*/

#include<cstdio>
#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

float abs ( float a )
{	if ( a < 0 )
		a*=-1;
	return a;
}

float func ( int *a, int n, int d );

int main()
{	int n,d;
	cin>>n>>d;
	int a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	cout<<"min cost: "<<func (a,n,d)<<endl;
	return 0;
}

float func ( int *a, int n, int d )
{	float cost=0;
	for ( int i=0; i<n; i++ )
		cost += a[i];
	cost /=(float)d;
	float val[n][d+1];
	memset(val,0,sizeof(val));
	for ( int i=1; i<=d; i++)
		val[0][i]=INT_MAX;
	val[0][0]=0;
	for ( int i=0; i<n; i++ )
	{	int sum=0;
		for ( int j=i; j<n; j++ )
			sum+=a[j];
		val[i][1]=abs(sum-cost);
	}
	for ( int i=n-1; i>=0; i-- )
	{	for ( int j=2; j<=d; j++ )
		{	int sum=0,k;
			float v1=INT_MAX, v2=INT_MAX;
			for ( k=i; k < n && sum+a[k] <= cost; k++ )
				sum+=a[k];
			if ( k < n )
				v1=val[k][j-1] + abs(sum-cost);
			if ( k+1 < n )
				v2=val[k+1][j-1] + abs(sum-cost+a[k]);
			if ( v1 < v2 )
				val[i][j]=v1;
			else
				val[i][j]=v2;
		}
	}
	for ( int i=0; i<n; i++ )
	{	for ( int j=0; j<=d; j++ )
			printf("%f ", val[i][j]);
		printf("\n");
	}
	return val[0][d];
}

/*
O(K*N^2)
http://cs.stackexchange.com/questions/19181/partition-array-into-k-subsets-each-with-balanced-sum

a[n] - pages in each chapter
Solution- cost - sum of all pages / days -> no. of pages that can be optimally read per day
Now we define cost as summation of deviation from this optimal cost for all days

val(i,j) - read ( i ->N-1) chapters in j days
val(0,j) for j>= 1 -> INT_MAX, read 0 chapters in j days -> WRONG ASSUMPTION since we want to partition for all 3 days -> INT_MAX
else
val(i,j) -> min { val(i+k-1,j-1), val(i+k,j-1) }
note what is k?
we have optimal cost - cost
sum (a[i] + a[i+1] + a[i+2] + ... +a[k-1]) <= cost
Now we have 2 choice wither to be within limit of cost or to exceed it ( choose kth chapter or not )
 and hence we choose minimum of the two

val(i,j)= min{	f(i+k-1,j-1) + sum(a[i+]+a[i+1] +... sum[k-1]) - cost
				Deviation from optimal cost is the parameter to be minimized
		arrange [k->N-1] chapters in j-1 days i.e we will read [i->k-1] on jth day

		f(i+k,j) + sum(a[i+]+a[i+1] +... sum[k-1]+sum[k]) - cost
                arrange [k+1->N-1] chapters in j-1 days i.e we will read [i->k] on jth day
	     }
And hence the DP
*/
		
