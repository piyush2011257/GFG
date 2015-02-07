#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;

int main()
{	int d, a[100];
	scanf("%d",&d);
	for ( int i=0; i<d; i++ )
		scanf("%d",a+i);
	sort(a,a+d);
	bool ctr=0;
	int min1, min1_low, min1_top;
        int min2, min2_low, min2_top;
	min1=INT_MAX-1;
	min2=INT_MIN+1;
	/*
	for ( int i=0; i<d; i++ )
		printf("%d-> %d\n",i,a[i]);
	*/
	for ( int i=0; i<d; i++ )
	{	int sum=-a[i];
		int low=i+1, top=d-1;
		while ( low < top )
		{	if ( a[low] + a[top] == sum )
			{	printf("yes %d %d %d\n",i,low,top);
				ctr=1;
				break;
			}
			else if ( a[low] + a[top] > sum )
			{	if ( a[low]+a[top] - sum < min1 )
				{	min1= a[low]+a[top]+a[i];
					min1_low=low;
					min1_top=top;
				}
				top--;
			}
			else
			{	if ( a[low]+a[top]-sum >  min2 )
                                {       min2= a[low]+a[top]+a[i];
                                        min2_low=low;
                                        min2_top=top;
				}
                                low++;
			}
		}
	}
	if ( ctr == 0 )
	{	if ( abs(min1) < abs(min2) )
			printf("%d\n", min1);
		else if ( abs(min1) > abs(min2) )
			printf("%d\n", min2);
		else
			printf("%d %d\n", min1, min2);
	}
	return 0;
}
