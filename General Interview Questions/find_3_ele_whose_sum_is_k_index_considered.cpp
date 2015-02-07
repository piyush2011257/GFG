#include<cstdio>
#include<map>
#include<vector>
using namespace std;

int main()
{	int a[100],K,d;
	scanf("%d",&d);
	// find i,j,k : i+j+k = K, no such condition that i != j, j != k and i != k
	map<int,vector<int> > m;
	for ( int i=0; i<d; i++ )
	{	scanf("%d",a+i);
		m[a[i]].push_back(i);
	}
	scanf("%d",&K);
	for ( int i=0; i<d; i++ )
	{	for ( int j=i+1; j<d; j++ )			// to aviod repetition of permutations of an o/p
		{	if ( j == i )
				continue;
			if ( m.count(K-a[i]-a[j]) != 0 )
			{	bool ctr=0;
				int l;
				for ( l=0; l < m[K-a[i]-a[j]].size(); l++ )
				{	if ( ( m[K-a[i]-a[j]][l] != i &&  m[K-a[i]-a[j]][l] != j ) && ( m[K-a[i]-a[j]][l]  > j ) )
					{	ctr=1;
						break;
					}
				}
				if ( ctr == 1 )
					printf("yes %d %d %d\n", i,j,m[K-a[i]-a[j]][l]);
			}
		}
	}
}
