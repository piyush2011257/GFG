/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-152-kindle-team-sde-1/
Array is given which is of 0 and 1, all connected 1 forms island. Find largest size island in given Array,

http://www.geeksforgeeks.org/find-number-of-islands/
Given a boolean 2D matrix, find the number of islands. This is an variation of the standard problem: “Counting number of connected components in a undirected graph”.
*/

#include<cstdio>
using namespace std;

const int len=8;
int dfs ( int a[len][len], bool visited[len][len], int i, int j );

int main()
{	int a[8][8]={	{1, 1, 1, 0, 1, 1, 1, 0},
                        {1, 1, 0, 1, 0, 1, 1, 1},
                        {0, 0, 1, 1, 1, 1, 1, 0},
                        {1, 1, 0, 0, 1, 0, 1, 0},
                        {0, 1, 0, 0, 0, 0, 1, 0},
			{1, 0, 1, 0, 0, 0, 0, 0},
			{1, 0, 1, 0, 1, 0, 1, 1},
			{0, 1, 0, 1, 0, 1, 0, 1}
		    };
	int mx=0, ct=0, count=0;
	bool visited[len][len]={0};
	for ( int i=0; i<len; i++ )
	{	for ( int j=0; j<len; j++ )
			if ( visited[i][j] == 0 && a[i][j] != 0  )
			{	count=dfs(a,visited,i,j);
				if ( count > mx )
					mx=count;
				ct++;
			}
	}
	printf("largest component: %d  number of components: %d\n", mx, ct);
	return 0;
}

int dfs ( int a[len][len], bool visited[len][len], int i, int j )
{	int ct=1;
	printf("%d %d\n",i,j);
	visited[i][j]=1;
	if ( i-1 >= 0 )
	{	if ( visited[i-1][j] == 0 && a[i-1][j] == 1 )
			ct += dfs(a,visited,i-1,j);
		if ( j-1 >= 0 )
		{	if ( visited[i-1][j-1] == 0 && a[i-1][j-1] == 1 )
                 	      ct += dfs(a,visited,i-1,j-1);
			 if ( visited[i][j-1] == 0 && a[i][j-1] == 1 )
                              ct += dfs(a,visited,i,j-1);
		}
		if ( j+1 < len )
                {       if ( visited[i-1][j+1] == 0 && a[i-1][j+1] == 1 )
                              ct += dfs(a,visited,i-1,j+1);
			 if ( visited[i][j+1] == 0 && a[i][j+1] == 1 )
                              ct += dfs(a,visited,i,j+1);
                }
	}
	if ( i+1 < len )
	{       if ( visited[i+1][j] == 0 && a[i+1][j] == 1 )
                        ct += dfs(a,visited,i+1,j);
                if ( j-1 >= 0 )
                {       if ( visited[i+1][j-1] == 0 && a[i+1][j-1] == 1 )
                              ct += dfs(a,visited,i+1,j-1);
                }
                if ( j+1 < len )
                {       if ( visited[i+1][j+1] == 0 && a[i+1][j+1] == 1 )
                              ct += dfs(a,visited,i+1,j+1);
                }
        }
	return ct;
}

/*
O(ROW*COL) solution, since each matrix element is visited once only.
ANother approach
(i,j) -> i*row+j th node
and change the matrix into graph

e.g
let matrix be
1 0
1 1

0,0 - 0
0,1 - 1
1,0 - 2
1,1 - 3

graph
0 -> 2, 3
2 -> 0, 3
3 -> 0, 1

now do dfs on undirected graph on each vertex
We need extra O(ROW*COL) space and then do dfs using list implementation. total ROW*COL vertices -> O(ROW*COL)
*/
*/
