/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-161-off-campus-sde-1-banglore/
Convert an integer to its roman. He asked me to consider cases with integers containing 4 and 9. I didn’t understand properly.

http://www.onlineconversion.com/roman_numerals_advanced.html

Corner case of 4 and 9
I 	The numeral one. II is two, III is three. You seldom see IIII as 4, since IV can also mean 4, plus its shorter to write.
V 	The numeral 5. IV is 4, VI is 6, VII is 7, VIII is 8.
X 	The numeral 10. IX is 9, XI is 11, etc.
L 	The numeral 50. XL would be 40.
C 	The numeral 100. Think of Century having a hundred years. C is short for the Latin word Centum, but that's not very easy to remember.
D 	The numeral 500.
M 	The numeral 1000.


For 1 - 49999

I II III
IV	( 1(I) less than 5(V) )
V VI VII VIII
IX	( 1(I) less than 10(X) )
X

X XX XXX	10-30
XL		( 10(X) less than 50 (L) )
L LX LXX LXXX	50-80
XC		( 10(X) less than 100 (C) )
C		100

C CC CCC	100-300
CD		400 ( 100(C) less than 500 (D) )
D DC DCC DCCC	500-800
CM		900
M		1000 ( 100(C) less than 1000 (M) )

This symmetry everywhere
M MM MMM MMMM MMMMM MMMMMMM MMMMMMM...  ( 1000 -> 9000 )

4984
MMMM CM LXXX IV
  4   9   8  4
*/

#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{	char a[]="4040";
	string s;
	if ( a[0] != '0' )
	{	int count= a[0]-'0';
		while ( count-- > 0 )
			s += 'M';
	}
	if ( a[1] != 0 )
	{	int count=a[1]-'0';
		if ( count <= 3 )
		{	while ( count-- > 0 )
				s += 'C';
		}
		else if ( count ==  4 )
			s += "CD";
		else if ( count <= 8 )
		{	s+='D';
			count-=5;
			while ( count-- > 0 )
				s +='C';
		}
		else if ( count == 9 )
			s += "CM";
	}
	if ( a[2] != 0 )
	{	int count=a[2]-'0';
		if ( count <= 3 )
		{	while ( count-- > 0 )
				s += 'X';
		}
		else if ( count ==  4 )
			s += "XL";
		else if ( count <= 8 )
		{	s+='L';
			count-=5;
			while ( count-- > 0 )
				s +='X';
		}
		else if ( count == 9 )
			s += "XC";
	}
	if ( a[3] != 0 )
	{	int count=a[3]-'0';
		if ( count <= 3 )
		{	while ( count-- > 0 )
				s += 'I';
		}
		else if ( count ==  4 )
			s += "IV";
		else if ( count <= 8 )
		{	s+='V';
			count-=5;
			while ( count-- > 0 )
				s +='I';
		}
		else if ( count == 9 )
			s += "IX";
	}
	cout<<s<<endl;		
	return 0;
}
