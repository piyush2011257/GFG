/*
https://www.youtube.com/watch?v=-8MwfgB-lyM
http://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
http://www.google.co.in/url?sa=t&rct=j&q=&esrc=s&source=web&cd=2&cad=rja&uact=8&sqi=2&ved=0CCMQFjAB&url=http%3A%2F%2Fwww.cse.iitd.ernet.in%2F~naveen%2Fcourses%2FCSL758%2FFord%2520Fulkerson%2520Algorithm.ppt&ei=n62_VJP5LqTcmAXJmIH4Cg&usg=AFQjCNHn-rorxKoGug8zdSID-cF-kn0ocA&bvm=bv.83829542,d.dGY

The below implementation of Ford Fulkerson Algorithm is called Edmonds-Karp Algorithm. The idea of Edmonds-Karp is to use BFS in Ford Fulkerson implementation as BFS always picks a path with minimum number of edges. When BFS is used, the worst case time complexity can be reduced to O(VE2). The above implementation uses adjacency matrix representation though where BFS takes O(V2) time, the time complexity of the above implementation is O(EV3)
http://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm#Algorithm
*/

#include<cstdio>
#include<queue>
#include<climits>
using namespace std;

void ford_fulkerson ( int s, int t, int n );
int bfs ( int s, int t, int n );

int G[100][100];

void print ( int n )
{	for ( int i=0; i<n; i++ )
	{	for ( int j=0; j<n; j++ )
			printf("%d ", G[i][j]);
		printf("\n");
	}
}

int main()
{	int n,e,s,t,u,v,wt;
	scanf("%d %d",&n,&e);
	for ( int i=0; i<e; i++ )
	{	scanf("%d %d %d",&u,&v,&wt);
		G[u][v]=wt;
		G[v][u]=0;
	}
	scanf("%d %d",&s,&t);
	ford_fulkerson(s,t,n);
	printf("\n");
	return 0;
}

void ford_fulkerson ( int s, int t, int n )
{	int tmp, sum=0;
	while ( tmp=bfs ( s,t,n), tmp != -1 )		// there exists a directed path still
		sum += tmp;		
	printf("Max flow / Min Cut: %d\n", sum);
}

// Special case of s == t  NOT Handled. in that case return -1
int bfs ( int s, int t, int n )
{	//printf("before bfs graph\n");
	//print(n);
	queue<int> q;
	bool in_queue[100]={0};
	int parent[100]={0};
	q.push(s);
	in_queue[s]=1;
	parent[s]=-1;
	int min=INT_MAX;
	bool found=0;
	do
	{	int i=q.front();
		if ( i == t )
		{	found=1;
			break;
		}
		q.pop();
		//printf("%d ", i);
		for ( int j=0; j<n; j++ )
		{	//printf("j- %d\n",j);
			if ( in_queue[j] == 0 && G[i][j] > 0 )
			{	//printf("yes\n");
				parent[j]=i;
				q.push(j);
				in_queue[j]=1;
				//if ( G[i][j] < min )
				//	min=G[i][j];
			}
		}
		//print(n);
	} while ( q.empty() == 0 );
	if ( found == 0 )
		return -1;
	int v=t;
	int u=parent[t];
	while ( u != -1 )
        {       if ( G[u][v] < min )
			min=G[u][v];
                v=u;
                u=parent[u];
        }
	v=t;
	u=parent[t];
        //printf("min: %d\npath: %d, ",min,v);
	while ( u != -1 )
	{	//printf("%d, ", u);
		G[u][v] -= min;
		G[v][u] += min;
		v=u;
		u=parent[u];
	}	// find min on path
	//printf("\n");
	//printf("Graph\n");
	//print(n);
	return min;
}

/*
8 15
0 1 10
0 2 5
0 3 15
1 2 4
2 3 4
2 5 8
2 6 6
3 6 16
1 5 15
1 4 9
4 5 15
5 6 15
4 7 10
5 7 10
6 7 10
0 7
Max flow / Min Cut: 25

8 15
0 1 10
0 2 5
0 3 15
1 2 4
2 3 4
2 5 8
6 2 6
3 6 16
1 5 15
1 4 9
4 5 15
5 6 15
4 7 10
5 7 10
6 7 10
0 7
Max flow / Min Cut: 28

6 10
0 1 16
0 2 13
1 2 10
2 1 4
1 3 12
3 2 9
2 4 14
4 3 7
4 5 4
3 5 20
0 5
Max flow / Min Cut: 23

*/
