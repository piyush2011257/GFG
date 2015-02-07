given matrix like :

a b e d
b c f e
a b d d
….

find the longest path of consecutive alphabets given a starting alphabet. You can move in all 8 directions. for eg. a->b(right)->c(down)->d(diagnal down)… len = 4 , find max such len

http://www.careercup.com/question?id=5727802043138048

This can be done very simply by creating a directed graph of all the letters and then doing a DFS search starting at every position to compute the longest consecutive String. O(n^2) complexity to create the graph with O(n^2) space and O(n^2) complexity to complete the DFS.

Alternately Dynamic Programming Question

func ( int a[][], int i, int j, int visited[][] )
{	v1=func(i+1,j+1)
	v2=func(i+1,j)
	v3=func(i+1,j-1)
	   func(i,j-1)
	   func(i,j+1)
	   func(i-1,j)
	   func(i-1,j-1)
	   func(i-1,j+1)

	CHECK
	i-1 >= 1
	i+1 <=N
	j-1 >= 1
	j+1 <= N at each stage
	and also a[X][Y]= a[x][y]+1	( Needs to be consecutive )
	No block is covered twice / can be covered twice since we want incremental alphabets. a -> b -> c- > b !!! 
								      a -> b -> c- > d ( b can come only once and hence that block

	mx=max{v1,v2...v7,v8}
	visited[i][j]=mx;

	Before calling func(I,J) check if visited[I][J] != -1 -> already solved an used memoized value


in main()
for ( i=1 -> N )
	for ( j=1 -> N )
		if visited[i][j] == -1
			func(a,i,j,visited)

Find max value amongst all visited[i][j]
