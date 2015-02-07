#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

void permute ( char *ch, int n, int i );

int main()
{	char ch[]="abcd";
	int n=strlen(ch);
	sort(ch,ch+n);
	//printf("%s\n",ch);
	permute(ch,n,0);
	return 0;
}

void permute ( char *ch, int n, int i )
{	if ( i == n )
	{	printf("%s\n",ch);
		return;
	}
	permute(ch,n,i+1);
	for ( int j=i+1; j<n; j++ )
	{	char tmp=ch[j];			// swap each i+kth character with ith character for k > 0 
		ch[j]=ch[i];
		ch[i]=tmp;
		permute(ch,n,i+1);
		tmp=ch[j];
		ch[j]=ch[i];
		ch[i]=tmp;
	}
}

/*
abcd

			ab - cd		abc - d		abcd
					abd - c		abdc

	a - bcd		ac - bd		acb - d		acbd
					acd - b		acdb

			ad - cb		adc - b		adcb
					adb - c		adbc

	b - acd
	c - bad
	d - bca

Ths way we get all permutations but NOT lexicographic order
For lexicographic ordering use usual brute-force ordering
*/
