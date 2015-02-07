www.geeksforgeeks.org/amazon-interview-experience-set-162/
Given a string of 0s and 1s, count the number of substring which start and end with 1.

http://www.geeksforgeeks.org/given-binary-string-count-number-substrings-start-end-1/
Given a binary string, count number of substrings that start and end with 1.

We can find count in O(n) using a single traversal of input string. Following are steps.
a) Count the number of 1’s. Let the count of 1’s be m.
b) Return m(m-1)/2
How?
Every substring {i,j} such that str[i->j] starts and ends with 1 -> str[i] == str[j] == 1
Thus there are 'm' possible values for i and j
mC2 - m(m-1)/2
Let these positions be in sorted order then
substring(i,j) -> valid
but substring(j,i) -> invalid iff i < j
1st smallest -> m-1
2d smallest -> m-2
3rd smallest -> m-3
4th smallest -> m-4
.  .. .
.  .. .
m-1 -> 1

m(m-1) - ( m(m-1)/2 ) -> m(m-1)/2
This includes substring having size >= 2

For including substrings of size 1 -> add m in the above expression
