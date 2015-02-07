/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-164-sde/

http://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/

Sum of two bits can be obtained by performing XOR (^) of the two bits. Carry bit can be obtained by performing AND (&) of two bits.

Logic
for two 1-bit numbers x and ya
x ^ y -> sum of x and y
x & y -> carry from addition of x and y

Lets generalize it
5+3
	101
	011
XOR	110		AND	001
XOR-> sum without any carry

Now carry -> 001 but this carry needs to be added on 2nd bit from LSB
carry -> carry << 1
	001 -> 010

Reflect the addition of carry using XOR
	110
	010
XOR	100		AND	010

Again carry on 2nd bit from LSB needs to be added on 3rd bit from LSB
carry -> carry << 1
	010 -> 100

To reflect addition of carry

	100
	100
XOR	000		AND	100

100 -> 1000

	 000
	1000
XOR	1000		AND	0000		<- CARRY IS 0 -> XOR is the sum since all carry have been added
1000 -> 101 + 011
8=5+3
*/

#include<stdio.h>
 
int Add(int x, int y)
{	 while (y != 0)
    	{	int carry = x & y; 
        	x = x ^ y;
        	y = carry << 1;
	}
	return x;
}
 
int Add_recursive(int x, int y)
{	if (y == 0)
        	return x;
    	else
        	return Add_recursive( x ^ y, (x & y) << 1);
}
int main()
{	printf("%d", Add(15, 32));
	return 0;
}
