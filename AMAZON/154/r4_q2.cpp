/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-154-sde2/

Q2. Transfer one file data from one PC to another PC. To transfer data some network entity is being used which cost some value. You need to reduce this cost of transferring the data. —> I used compression technique to replace repetitive data with some key on first PC and put it back on another PC.

http://www.geeksforgeeks.org/run-length-encoding/

Run Length Encoding
Given an input string, write a function that returns the Run Length Encoded string for the input string. For example, if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″
*/

#include<cstdio>
using namespace std;

void func ( char *ch );

int main()
{	char ch[100];
	scanf("%s",ch);
	func(ch);
	return 0;
}

void func ( char *ch )
{	int i=0, j, k=0,count;
	char new_ch[100];
	while ( ch[i] != '\0' )
	{	j=i;
		count=0;
		while ( ch[j] != '\0' && ch[j] == ch[i] )
			j++,count++;
		new_ch[k++]=ch[i];
		if ( count > 1 )
			new_ch[k++]=(char)(count+48);
		i=j;
	}
	new_ch[k]='\0';
	printf("%s\n", new_ch);
}
		
	
