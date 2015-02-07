#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

void func ( string &ch, int n, int pos);

int main()
{	string ch="My name  is   Piyush    Raman";
	int n=ch.length();
	func(ch,n,0);
	cout<<ch<<endl;	
	return 0;
}

void func ( string &ch, int n, int pos )
{	// assume multiple spaces
	string t;
	while ( pos < n && ch[pos]==' ' )
	{	t += ' ' ;
		pos++;
	}
	if ( pos == n )			// only spaces
	{	ch.clear();
		ch += t;
		return;
	}
	int i;
	string s;
	for ( i=pos; i < n && ch[i] != ' '; i++ )
		s += ch[i];
	func(ch,n,i);
	ch += s;
	ch += t;
	cout<<ch<<endl;
}
