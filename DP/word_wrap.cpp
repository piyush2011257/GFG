/*
http://www.geeksforgeeks.org/dynamic-programming-set-18-word-wrap/
Given a sequence of words, and a limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly. Assume that the length of each word is smaller than the line width.
*/

#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;

int func ( vector<int> v, int w );

int main()
{	char str[20];
	vector<int> v;
	int w;
	cin>>w;
	while ( scanf("%s",str) != EOF )
		v.push_back(strlen(str));
	//for ( int i=0; i<v.size(); i++ )
	//	printf("%d ", v[i]);
	//printf("\n");
	cout<<func(v,w)<<endl;
	return 0;
}


int func ( vector<int> v, int w )
{	int n=v.size();
	int cost[n][n];
	int sum[n], len, min;
	memset(sum,0,sizeof(sum));
	sum[0]=v[0];
	for ( int i=1; i<n; i++ )
		sum[i] = sum[i-1] + v[i];
	memset(cost,0,sizeof(cost));
	for ( int i=0; i<n; i++ )
	{	cost[i][i]=w-v[i];
         	cost[i][i] *= w-v[i];
                cost[i][i] *= w-v[i];
        }
	/*
	Logic like pallindromic partitioning / MCM
	Each word is denoted by its length in vector<> v
	f(i,j) -> optimal cost for word i -> word j
	f(i,j) -> if length of word i + word i+1 + word i+2 + ... + word j-1 + word j + (j-i) <= W -> then no need of new line
									       ( for spaces between j-i+1 words )
	in this case cost= W - (summation of length of words from i -> j) + (j-i )
									   for spaces
	cost = cost ^3

	Else is the words from i->j cannot fit into one line then try breaking each cluster
	E.g. 4 words ABCD
		A/BCD	after A word a new line and then arrange BCD
		AB/CD	arrange AB and then a new line and then arrange CD
		ABC/D	arrange ABC and then a new line and then arrange D
		choose minimum cost amongst the above paritions
		f(i,j) = min { k=i -> j-1 f(i,k) + f(k+1,j) }

	Same approach in GFG indirectly
	*/
	for ( int i=n-1; i>=0; i-- )
	{	for ( int j=i+1; j<n; j++ )
		{	if ( i != 0 )
				len = sum[j] - sum[i-1];
			else
				len=sum[j];
			// cout<<i<<" "<<j<<" "<<len<<endl;
			if ( len + (j-i)  <= w )
			{	cost[i][j]=w-len-j+i;
				cost[i][j] *= w-len-j+i;
				cost[i][j] *= w-len-j+i;
			}
			else
			{	min=INT_MAX;
				for ( int k=i; k<j; k++ )
					if ( cost[i][k] + cost[k+1][j] < min )
						min=cost[i][k] + cost[k+1][j];
				cost[i][j]=min;
			}
		}
	}
	/*
	for ( int i=0; i<n; i++ )
	{	for ( int j=0; j<n; j++ )
			printf("%d ", cost[i][j]);
		printf("\n");
	}
	*/
	return cost[0][n-1];
}

/*
Why greedy fails??

Method 1 (Greedy Solution)
The greedy solution is to place as many words as possible in the first line. Then do the same thing for the second line and so on until all words are placed. This solution gives optimal solution for many cases, but doesn’t give optimal solution in all cases. For example, consider the following string “aaa bb cc ddddd” and line width as 6. Greedy method will produce following output.

aaa bb 
cc 
ddddd

Extra spaces in the above 3 lines are 0, 4 and 1 respectively. So total cost is 0 + 64 + 1 = 65.

But the above solution is not the best solution. Following arrangement has more balanced spaces. Therefore less value of total cost function.

aaa
bb cc
ddddd

Extra spaces in the above 3 lines are 3, 1 and 1 respectively. So total cost is 27 + 1 + 1 = 29.
*/
