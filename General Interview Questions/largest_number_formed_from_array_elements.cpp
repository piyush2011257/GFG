/*
http://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
Suppose
8
15
16
42
4
0

8
4	
4	2
1	6
1	5
0

Algorithm-

Consider 2 numbers a1 and a2

i=0
while ( a1[i] == a2[i] and not end of a1 and a2 )
        i++;

if not end of a1 and a2
        a1[i] > a2[i]
                a1a2
        else
                a2a1

if end of a1 and not of a2 or vice versa
        if ( a2[i+1] > a2[0] )
                a2a1
        else
                a1a2
2343..
234

3 > 2

234 3 ..234	-> Larger
234 2 343...

if both end i.e. equal a1a2 == a2a1

Given an array of numbers, arrange them in a way that yields the largest value. For example, if the given numbers are {54, 546, 548, 60}, the arrangement 6054854654 gives the largest value. And if the given numbers are {1, 34, 3, 98, 9, 76, 45, 4}, then the arrangement 998764543431 gives the largest value.

A simple solution that comes to our mind is to sort all numbers in descending order, but simply sorting doesn’t work. For example, 548 is greater than 60, but in output 60 comes before 548. As a second example, 98 is greater than 9, but 9 comes before 98 in output.

So how do we go about it? The idea is to use any comparison based sorting algorithm. In the used sorting algorithm, instead of using the default comparison, write a comparison function myCompare() and use it to sort numbers. Given two numbers X and Y, how should myCompare() decide which number to put first – we compare two numbers XY (Y appended at the end of X) and YX (X appended at the end of Y). If XY is larger, then X should come before Y in output, else Y should come before. For example, let X and Y be 542 and 60. To compare X and Y, we compare 54260 and 60542. Since 60542 is greater than 54260, we put Y first.

Refer 164 R4_Q3
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int myCompare(string X, string Y)			// Sorting comparator changed
{	string XY = X.append(Y);			// strcat()
	string YX = Y.append(X);
    	return XY.compare(YX) > 0 ? 1: 0;
}

/*
8 4 42 15 16 0

8
4
4	2
1	6
1	4
0

*/
 
void printLargest(vector<string> arr)
{	sort(arr.begin(), arr.end(), myCompare);
	for (int i=0; i < arr.size() ; i++ )
        	cout << arr[i];
	cout<<endl;
}
 
int main()
{	vector<string> arr;
    	arr.push_back("54");
    	arr.push_back("546");
    	arr.push_back("548");
    	arr.push_back("60");
    	printLargest(arr);
	/*arr.push_back("7");
    	arr.push_back("776");
    	arr.push_back("7");
    	arr.push_back("7");*/
 	//output should be 998764543431
    	/*arr.push_back("1");
    	arr.push_back("34");
    	arr.push_back("3");
    	arr.push_back("98");
    	arr.push_back("9");
    	arr.push_back("76");
    	arr.push_back("45");
    	arr.push_back("4");
    	*/
   	return 0;
}
