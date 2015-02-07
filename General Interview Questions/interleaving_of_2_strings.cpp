#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

void func ( char *str1, char *str2, string s);

int main()
{	char ch1[]="AB";
	char ch2[]="CD";
	string s;
	func(ch1,ch2,s);
	return 0;
}

void func ( char *str1, char *str2 , string s)
{	//printf("%c %c\n", *str1, *str2);
	if ( *str1 == '\0' && *str2 =='\0' )
	{	cout<<s<<endl;
		return;
	}
	if ( *str1 != '\0' )
		func ( str1+1, str2,s+(*str1));
	if ( *str2 != '\0' )
		func ( str1,str2+1,s+(*str2));
}

/* 
An interleaved ordering of string preserves the ordering of string in each individual string
*/
