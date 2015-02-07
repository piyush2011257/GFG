#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

void combine ( char *ch, int n, int i, string s );

int main()
{	char ch[]="abcd";
	int n=strlen(ch);
	sort(ch,ch+n);
	//printf("%s\n",ch);
	string s;
	combine(ch,n,0,s);
	return 0;
}

void combine ( char *ch, int n, int i, string s )
{	if ( i == n )
		return;
	cout<<s+ch[i]<<endl;
	combine(ch,n,i+1,s+ch[i]);
	for ( int j=i+1; j<n; j++ )
	{	cout<<s+ch[j]<<endl;
		combine(ch,n,j+1,s+ch[j]);
	}
	
}

/*
abcd

a	ab	abc	abcd
		abd
	ac	acd
	ad

b	bc	bcd
	bd

c	cd

d
*/
