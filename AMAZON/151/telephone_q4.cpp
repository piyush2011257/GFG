/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-151-sde/
Write a program to show whether a graph is a tree or not using adjacency matrix.
*/

#include<cstdio>
using namespace std;

/*
Use logic of detecting cycles in Graphs ( Directed / Undirected ) on a matrix
Do DFS on the graphs in matrix form

Directed Graph
if ( in_stack[i] == 1 ) means cycle

Undirected GRaph
if ( visited[i] == 1 ) means cycle
*/

const int len=3;

bool func ( int a[len][len], bool *visited, int i, int caller );
bool func_dir ( int a[len][len], bool *visited, int i );

int main()
{	/*int a[len][len]={{0,1,1,0,0,0,0},
			 {1,0,0,1,1,0,0},
			 {1,0,0,0,0,1,1},
			 {0,1,0,0,0,0,0},
			 {0,1,0,0,0,0,0},
			 {0,0,1,0,0,0,1},
			 {0,0,1,0,0,1,0},
			};
	*/
	int a[len][len]={{0,1,0},
			 {0,0,1},
			 {1,0,0},
			};
	bool visited[len]={0}, in_stack[len]={0};
	printf("0- cycle present\n1- no cycle present\n");
	printf("%d\n", func(a,visited,0,-1));
	printf("%d\n", func_dir(a,in_stack,0));
	return 0;
}

// Undirected graph
bool func ( int a[len][len], bool *visited, int i, int caller)
{	if ( visited[i] == 1 )
		return 0;
	visited[i]=1;
	bool v1=1;
	for ( int j=0; j<len; j++ )
	{	if ( j == caller )
			continue;
		if ( a[i][j] == 1 && visited[j] == 1 )
			return 0;
		else if ( a[i][j] == 1 )
		{	v1 = v1 & ( func(a,visited,j,i) );
			if ( v1 == 0 )
				return 0;
		}
	}
	return 1;
}

// Directed Graphs
bool func_dir ( int a[len][len], bool *in_stack, int i)
{       printf("i: %d\n",i);
	if ( in_stack[i] == 1 )
                return 0;
        in_stack[i]=1;
        bool v1=1;
        for ( int j=0; j<len; j++ )
        {       if ( a[i][j] == 1 )
		{	if ( in_stack[j] == 1 )
                        	return 0;
			else
			{       v1 = v1 & ( func_dir(a,in_stack,j) );
                        	if ( v1 == 0 )
                                	return 0;
                	}
		}
        }
	in_stack[i]=0;
        return 1;
}
