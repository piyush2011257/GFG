#include<cstdio>
#include<map>
using namespace std;

int main()
{	int a[100],K,d;
	scanf("%d",&d);
	// find i,j,k : i+j+k = K, no such condition that i != j, j != k and i != k
	map<int,bool> m;
	for ( int i=0; i<d; i++ )
	{	scanf("%d",a+i);
		m[a[i]]=1;
	}
	scanf("%d",&K);
	for ( int i=0; i<d; i++ )
	{	for ( int j=0; j<d; j++ )
		{	if ( m.count(K-a[i]-a[j]) != 0 )
				printf("yes %d %d %d\n", a[i],a[j],K-a[i]-a[j]);
		}
	}
}
