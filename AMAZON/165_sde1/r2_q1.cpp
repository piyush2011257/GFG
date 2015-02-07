/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-165-sde/
Given a number of friends who has to give or take some amount of money from one another. Design an algorithm by which the total cash flow among all the friends is minimized. Specify the data structure which you will use and write the code for it.

http://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/
*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int abs ( int a );
void minimize_cash_flow( int *net, int n );
int max_out ( int *net, int n );
int max_in ( int *net, int n );

int main()
{	int n,e,u,v,wt;
	cin>>n>>e;
	int in[n], out[n], net[n];
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	memset(net,0,sizeof(net));
	for ( int i=0; i<e; i++ )
	{	cin>>u>>v>>wt;
		in[v]+=wt;
		out[u]+=wt;
	}
	for ( int i=0; i<n; i++ )
		net[i] = in[i] - out[i];
	minimize_cash_flow(net,n);
	return 0;
}

int abs ( int a )
{	return a*(-1);	}

void minimize_cash_flow( int *net, int n )
{	int pos_max_out=max_out(net,n);
	int pos_max_in=max_in(net,n);
	if ( pos_max_out == -1 && pos_max_in == -1 )
		return;
	int val= (abs(net[pos_max_out]) < net[pos_max_in] ) ? abs(net[pos_max_out]) : net[pos_max_in];
	net[pos_max_out] += val;
	cout<<pos_max_in<<" got "<<val<<" from "<<pos_max_out<<endl;
	net[pos_max_in] -= val;
	minimize_cash_flow(net,n);
}

int max_out ( int *net, int n )
{	int min=0, idx=-1;
	for ( int i=0; i<n; i++ )
		if ( net[i] < 0 && net[i] < min )
		{	min=net[i];
			idx=i;
		}
	return idx;
}

int max_in ( int *net, int n )
{       int max=0, idx=-1;
        for ( int i=0; i<n; i++ )
                if ( net[i] > 0 && net[i] > max )
                {       max=net[i];
                        idx=i;
                }
        return idx;
}

/*
O(N^2)
How?
AT each call net[] for at least 1 person becomes 0
And we need to make net =0 for all - N recursions
And for each recursion, we need to find min / max - O(N)
O(N*N) = O(N^2)

If one amount is 0, the other will also be 0. It's because the sum of all the amounts is null. So the conjunction and the disjunction are equivalent.

e.g.
0 1 1000
0 2 2000
1 2 5000

		0		1		2
net		-1000		+1000


                0               1               2
net            -1000		+1000		+2000
	       -2000				


                0               1               2
net            -1000           +1000		+2000
	       -2000	       -5000		+5000

See at each stage total sum is getting 0		


Now the money is being circulated is amongst friends only. What matters is that at the end the net[] value for each friend must be same. It doesnt matter who gives money to whom, but the final net[] value must be same. Hence using this logic and greedy approach, to settle largest creditor with largest debitor. We get the solution
*/
