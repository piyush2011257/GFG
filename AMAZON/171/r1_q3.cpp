/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-171/

http://www.geeksforgeeks.org/find-next-greater-number-set-digits/
Given a number n, find the smallest number that has same set of digits as n and is greater than n. If x is the greatest possible number with its set of digits, then print “not possible”.
*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;

void func (string str );

int main()
{	string str;
	cin>>str;
	func(str);
	return 0;
}

void func (string str )
{	int n=str.length(), i;
	i=n-2;
	while ( i >= 0 && str[i] >= str[i+1] )
		i--;
	if ( i == -1 )
	{	printf("Not possible\n");
		return;
	}
	int min=i+1;
	for ( int j=i+1; j<n; j++ )
	{	if ( str[j] > str[i] &&  str[j] < str[min] )
			min=j;
	}
	cout<<i<<" "<<min<<endl;
	str[min]=str[min]^str[i];
	str[i]=str[min]^str[i];
	str[min]=str[min]^str[i];
	sort(str.begin()+i+1, str.end());
	cout<<str<<endl;
}		
