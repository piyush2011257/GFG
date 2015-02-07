/*
http://www.geeksforgeeks.org/snapdeal-interview-experience-set-7-campus/
http://www.geeksforgeeks.org/power-set/
*/
#include<cstdio>
#include<iostream>
using namespace std;

void func ( char *a, int i, int n, char *ch, int pos  );

int main()
{	int n;
	cin>>n;
	char a[n];
	char ch[n+1];
	cin>>a;
	for ( int i=0; i<n; i++ )
		func(a,i,n,ch,0);
	cout<<"{}"<<endl;			// empty set
	return 0;
}
// Recursive
void func ( char *a, int i, int n, char *ch, int pos  )
{	if ( i == n )
	{	ch[pos]='\0';
		cout<<ch<<endl;
		return;
	}
	ch[pos]=a[i];
	ch[pos+1]='\0';
	//cout<<"pos: "<<pos<<endl;
	cout<<ch<<endl;
	for ( int j=i+1; j<n; j++ )
		func(a,j,n,ch,pos+1);
}
