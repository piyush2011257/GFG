/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-169-sde-2/
Write a program to convert a integer to its form in a given language .
For example 112345 Could be one hundred twelve thousand three hundred forty five or One lac twelve thousand three hundred forty five.
*/

#include<cstdio>
#include<map>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void func ( string str, int len, int start, string &output );

map<char,string> m1;
map<int,string> m2;
map<int,string> m3;
map<char,string> m4;
map<string,string> m5;

int main()
{	string str;
	
	m1['0']="zero";
	m1['1']="one";
	m1['2']="two";
	m1['3']="three";
	m1['4']="four";
	m1['5']="five";
	m1['6']="six";
	m1['7']="seven";
	m1['8']="eight";
	m1['9']="nine";
	m2[1]="thousand";
	m2[2]="million";
	m2[3]="billion";
	m2[4]="trillion";
	m3[2]="hundred";
	m4['2']="twenty";
	m4['3']="thirty";
	m4['4']="forty";
	m4['5']="fifty";
	m4['6']="sixty";
	m4['7']="seventy";
	m4['8']="eighty";
	m4['9']="ninty";
        m5["01"]="one";
        m5["02"]="two";
        m5["03"]="three";
        m5["04"]="four";
        m5["05"]="five";
        m5["06"]="six";
        m5["07"]="seven";
        m5["08"]="eight";
        m5["09"]="nine";
	m5["10"]="ten";
	m5["11"]="eleven";
	m5["12"]="twelve";
	m5["13"]="thirteen";
	m5["14"]="fourteen";
	m5["15"]="fifteen";
	m5["16"]="sizteen";
	m5["17"]="seventeen";
	m5["18"]="eighteen";
	m5["19"]="nineteen";
	cin>>str;
	int len=str.length()-1;
        len=len/3;
	string output;
	func(str,len,0,output);
	cout<<output<<endl;
	return 0;
}

void func ( string str, int len, int start, string &output )
{	string tmp;
	int end=(str.length()-1)-(len)*3;
	cout<<start<<" "<<end<<endl;
	bool non_zero=0;
	if ( end-start+1 == 3 )
	{	if ( str[start] != '0' )
		{	output += m1[str[start]];
			output += " hundred ";
			non_zero=1;
		}
        	tmp +=str[start+1];
                tmp +=str[end];
                if ( m5.count(tmp) == 1 )
                {	output += m5[tmp];
			non_zero=1;
		}
                else
                {       if ( !(tmp[0] == '0' && tmp[1] =='0') )		// 100
			{	output += m4[str[start+1]];
				output += " ";
                        	output += m1[str[end]];
				non_zero=1;
			}
                }
	}
	else if ( end-start+1 == 2 )
	{	tmp +=str[start];
		tmp +=str[end];
		if ( m5.count(tmp) == 1 )
		{	output += m5[tmp];
			non_zero=1;
		}
		else
		{	if ( ! ( tmp[0] =='0' && tmp[1] =='0' ) )
			{	output += m4[str[start]];
				output += " ";
				output += m1[str[end]];
				non_zero=1;
			}
		}
	}
	else
	{	if ( len > 0 && str[start] != '0' || len == 0 )		// only 0
		{	output += m1[str[start]];
			non_zero=1;
		}
	}
	if ( non_zero == 1 )
		output += " ";
	if ( len > 0 )
	{	if ( non_zero == 1 )
		{	output += m2[len];		// 10000000
			output += " ";
		}
		func(str,len-1,end+1,output);
	}
}
