/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-173-campus/
 You are given a string that represent an expression of digits and operands. Eg. 1+2*3 , 1-2+4. You need to evaluate the string or the expression. NO BODMAS is followed. If the expression is of incorrect syntax return -1.
Test cases :
a) 1+2*3 will be evaluated to 9.
b) 4-2+6*3 will be evaluated to 24.
c) 1++2 will be evaluated to -1(INVALID).
Also, in the string spaces can occur. For that case we need to ignore the spaces. Like :- 1*2 -1 is equals to 1.

FIrst check for validity
NCNCNCNCNC
number
character
if valid then solve using queue else show error

*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<stack>
using namespace std;

int solve ( int op1, int op2, char op )
{	if ( op == '+' )
		return op1 + op2;
	if ( op == '-' )
                return op1 - op2;
	if ( op == '*' )
                return op1 * op2;
	if ( op == '/' )
                return op1 / op2;
	cout<<"invalid operator"<<endl;
	exit(0);
}

bool is_operator ( char ch )
{	return ch== '+' || ch =='-' || ch =='*' || ch == '/';
}

bool is_operand ( char ch )
{	return ch>= '0' && ch <= '9' ;	}

int main()
{	char tch[100], ch[100];
	scanf("%[^\n]s",tch);			// include spaces in i/p
	int n=strlen(tch),i,j;
	for ( i=0, j=0; i<n; i++ )
		if ( tch[i] != ' ' )
			ch[j++]=tch[i];
	ch[j]='\0';
	n=strlen(ch);
	for ( int i=0; i<n; i+=2 )			// i/p format - NCNCNCNCNC.....CN	starts / ends with N aletrnately with C
	{	if ( is_operand(ch[i]) == 0 )
		{	cout<<"Error at "<<i<<" .Not operand"<<endl;
			return 0;
		}
		if ( i+1 < n && is_operator(ch[i+1]) == 0 )
		{       cout<<"Error at "<<i+1<<" .Not operator"<<endl;
                        return 0;
                }
	}
	if ( is_operand(ch[n-1]) == 0 )			// Ends in oprand
	{       cout<<"Error at "<<n-1<<" .Ending with operator"<<endl;
  		return 0;
        }
 	// Reach here if valid only
	if ( n == 1 )
	{	cout<<ch[0]<<endl;
		return 0;
	}
	int op1=ch[0]-'0';
	int op2=ch[2]-'0';
	char op=ch[1];
	//cout<<op1<<" "<<op2<<" "<<op<<endl;       	
	op1=solve(op1,op2,op);
	for ( int i=3; i<n; i++ )
	{	op=ch[i];
		i++;
		op2=ch[i]-'0';
		//cout<<op1<<" "<<op2<<" "<<op<<" "<<i<<endl;
		op1=solve(op1,op2,op);
	}
	cout<<op1<<endl;
	return 0;
}
