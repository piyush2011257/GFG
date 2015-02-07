/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-150-sde1-1-year-experienced/
http://www.geeksforgeeks.org/next-greater-element/ (use stacks)

http://www.geeksforgeeks.org/next-greater-element/
Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1. 

Method 2 (Using Stack)
Thanks to pchild for suggesting following approach.
1) Push the first element to stack.
2) Pick rest of the elements one by one and follow following steps in loop.
….a) Mark the current element as next.
….b) If stack is not empty, then pop an element from stack and compare it with next.
….c) If next is greater than the popped element, then next is the next greater element fot the popped element.
….d) Keep poppoing from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements
….g) If next is smaller than the popped element, then push the popped element back.
3) After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them
*/

#include<stack>
#include<cstdio>
using namespace std;

const int n=8;

int main()
{	int a[n]={1,2,3,4,3,2,3,4};
	stack<int>s;
	int next_greater[n];
	s.push(0);
	for ( int i=1; i<n; i++ )
	{	// stack contains unsolved problem
		while ( s.empty() == 0 && a[i] > a[s.top()] )
		{	printf("called\n");
			next_greater[s.top()]=i;
			s.pop();
		}
		s.push(i);
		if ( s.empty() == 0 )
			printf("i:%d top: %d\n",i,a[s.top()]);
	}
	while (s.empty() == 0 )
	{	next_greater[s.top()]=-1;
		s.pop();
	}
	for ( int i=0; i<n; i++ )
		printf("%d ", next_greater[i]);
	return 0;
}
	
