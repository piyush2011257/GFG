/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-164-sde/
Given an array of positive integers, form a largest decimal number by concatenating integers. Such that the largest number should be divided by 2, 3 and 5.

http://www.geeksforgeeks.org/find-the-largest-multiple-of-2-3-and-5/
http://www.geeksforgeeks.org/find-the-largest-number-multiple-of-3/

Algorithmic Proof-

Let Sum = a+b+c+d
sum%mod = ( a+b+c+d)%mod = a%mod + b%mod + c%mod + d%mod

a%3 = 0
    = 1
    = 2

Case 1-
if sum % mod == 1
( a + b + c +d ) %mod == 1
a%mod + b%mod + c%mod + d%mod = 1

if there exists at least 1 file having %mod == 1, let us assume that d%mod == 1
sum%mod = (a+b+c+d)%mod = 1
= (a+b+c)%mod +d%mod
= (0 + 1)%mod
So if we remove d ->
= (a+b+c)%mod
= (0 )%mod
= 0
So remove smallest element : ele %mod == 1

if no %1??
2%3=2
(2+2)%3=1				<- == 1
(2+2+2)%3=0
(2+2+2+2)%3=2
(2+2+2+2+2)%3=1
(2+2+2+2+2+)%3=0			<- == 1


So if we have
(a+b+c+d+e+f)%3 == 1
and there exists no %3 == 1
but
lets assume b%c == 2 and c%mod == 1
sum%3 = (a+b+c+d+e+f)%3 = 2
a%3 + (b%3 + c%3) + d%3 + e%3 f%3
(b%3 + c%3) + a%3 + d%3 + e%3 f%3
(2+2)%3 + 0
4%3 + 0
1%3 + 0

if we remove b and c
a%3 + d%3 + e%3 f%3
=0
and hence we have the solution

so if sum of digits % 3 == 1
remove smallest ele : ele %3 == 1
or
remove two smallest ele's : ele%3 == 2


if sum%3 == 2
(a+b+c+d+e+f)%3
Similarly
remove smallest ele : ele%3==2
or
remove 2 smallest ele's : ele%3 == 1


The above method can be optimized in following ways.
1) We can use Heap Sort or Merge Sort to make the time complexity O(nLogn).

2) We can avoid extra space for queues. We know at most two items will be removed from the input array. So we can keep track of two items in two variables. Directly store 2 %3=1 and %3=2 smallest values along with the index

3) At the end, instead of sorting the array again in descending order, we can print the ascending sorted array in reverse order. While printing in reverse order, we can skip the two elements to be removed.
Consider
{ 4, 8, 15, 16, 23, 42,0 }
o/p- 42231615840
WRONG
we can add 8 in the position to ger the largest digit

mod_is_1[2]={-1,-1}
mod_is_2[2]={-1,-1}
during print check for which ever case and check if the index belongs to the array. If yes, then skip it
Refer-
largest_number_formed_from_array_elements.cpp
http://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
*/


#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

const int len=7;

int main()
{	int a[len]={ 4, 8, 15, 16, 23, 42,0 };//{8, 1, 7, 6, 0};
	bool has_zero=0;
	int sum=0;
	for ( int i=0; i<len; i++ )
		if (a[i] == 0 )
		{	has_zero=1;
			break;
		}
	if ( has_zero == 0 )
	{	printf("No 0\n");
		return 0;
	}
	queue<int>q0;
	queue<int>q1;
	queue<int>q2;
	for ( int i=0; i<len; i++ )
		sum += a[i];
	//printf("sum: %d\n",sum);
	if ( sum%3 == 0 )
	{	printf("yeah\n");
		sort(a,a+len);
		for ( int i=len-1;i>=0;i-- )
			printf("%d",a[i]);
		printf("\n");
		return 0;
	}
	sort(a,a+len);
	for ( int i=0; i<len; i++ )
		if ( a[i]%3 == 0 )
			q0.push(a[i]);
		else if ( a[i]%3 == 1 )
                        q1.push(a[i]);
		else
			q2.push(a[i]);
        int n=len;        
	if ( sum%3 == 1 )
	{	int tarr[len], j=0;
		if ( q1.empty() == 0 )
		{	q1.pop();
			while ( q1.empty() == 0 )
			{	tarr[j++]=q1.front();
				q1.pop();
			}
			while (q2.empty() == 0 )
			{       tarr[j++]=q2.front();
                                q2.pop();
                        }
                        while (q0.empty() == 0 )
                        {       tarr[j++]=q0.front();
                                q0.pop();
                        }
			sort(tarr,tarr+j);
			for ( int i=j-1;i>=0;i-- )
        	                printf("%d",tarr[i]);
                	printf("\n");
			return 0;
		}
		else
		{	if ( q2.empty() == 1 )
			{	printf("Not possible\n");
				return 0;
			}
			q2.pop();
			if ( q2.empty() == 1 )
                        {       printf("Not possible\n");
                                return 0;
                        }
                        q2.pop();
                        while ( q1.empty() == 0 )
                        {       tarr[j++]=q1.front();
                                q1.pop();
                        }
			while (q2.empty() == 0 )
                        {       tarr[j++]=q2.front();
                                q2.pop();
                        }
                        while (q0.empty() == 0 )
                        {       tarr[j++]=q0.front();
                                q0.pop();
                        }
			sort(tarr,tarr+j);
                        for ( int i=j-1;i>=0;i-- )
                                printf("%d",tarr[i]);
                        printf("\n");
                        return 0;
		}
	}
	else
	{       int tarr[len], j=0;
                if ( q2.empty() == 0 )
                {       q2.pop();
                        while ( q1.empty() == 0 )
                        {       tarr[j++]=q1.front();
                                q1.pop();
                        }
                        while (q2.empty() == 0 )
                        {       tarr[j++]=q2.front();
                                q2.pop();
                        }
                        while (q0.empty() == 0 )
                        {       tarr[j++]=q0.front();
                                q0.pop();
                        }
                        sort(tarr,tarr+j);
                        for ( int i=n-1;i>=0;i-- )
                                printf("%d",tarr[i]);
                        printf("\n");
                        return 0;
                }
                else
                {       if ( q1.empty() == 1 )
                        {       printf("Not possible\n");
                                return 0;
                        }
                        q1.pop();
                        if ( q1.empty() == 1 )
                        {       printf("Not possible\n");
                                return 0;
                        }
                        q1.pop();
                        while ( q1.empty() == 0 )
                        {       tarr[j++]=q1.front();
                                q1.pop();
                        }
                        while (q2.empty() == 0 )
			{       tarr[j++]=q2.front();
                                q2.pop();
                        }
                        while (q0.empty() == 0 )
                        {       tarr[j++]=q0.front();
                                q0.pop();
                        }
                        sort(tarr,tarr+j);
                        for ( int i=n-1;i>=0;i-- )
                                printf("%d",tarr[i]);
                        printf("\n");
                        return 0;
                }
        }
	return 0;
}
