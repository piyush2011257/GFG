#include<cstdio>
#include<algorithm>
using namespace std;

void func ( int *a, int n, int med, int k );

int main()
{	int a[100];
	int n;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ )
		scanf("%d",a+i);
	sort(a,a+n);
	int med=n/2 - ((n%2) == 0 );
	int k;
	scanf("%d",&k);
	func(a,n,med,k);
	return 0;
}

void func ( int *a, int n, int med, int k )
{	//printf("%d\n", a[med]);
	int left=med-1, right=med+1;
	int ct=0;
	while ( left >= 0 && right < n && ct < k )
	{	//printf("%d %d %d\n",left,right,ct);
		if ( ( a[med] - a[left] ) <= ( a[right] - a[med] ) )
			left--;
		else
			right++;
		ct++;
	}
	while ( left >= 0 && ct < k )
		left--;
	while ( right < n && ct < k )
		right++;
	printf("%d %d\n",left+1,right-1);
}
