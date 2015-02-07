Given array of 0’s and 1’s. All 0’s are coming first followed by 1’s. find the position of first 1
Ex 0000111 o/p : 4
Again he modified it . Do the same if stream is coming 00000000……..1111111……
In less than O(N)

For a stream case
Consider question equivalent to having huge building with unknown height and find the height at which egg breaks - NK (Search / Sort )
Read 2 chars and see if last char is 1
Read 4 chars and see if last char is 1
Read 8 chars and see if last char is 1
Read 16 chars and see if last char is 1
..
..
..
Read 2^k chars and see if last char is 1
if at kth iteration last char is 1 -> re-analyze [ 2^(k-1), 2^k ] area using same logic
Log2(N) + Log2(N/2)
-> O(LogN) solution time


