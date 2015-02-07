http://www.geeksforgeeks.org/amazon-interview-questions-set-147/
A big unsorted array of numbers are given.Each number is big of almost 10bits.How to sort these numbers?

Note 10-bit number -> 2^10 -> 1024 different numbers
At max 1024 different numbers in the BIG ARRAY. Now we know the range already and it is very small -> Counting Sort
Keeg on reading the input stream and sort using counting sort. since range -> [0,1024] only

O(N) solution

Rest all needs-
Merge Sort- O(NlogN) time, O(N) space
Quick Sort- O(N^2) time, O(1) space
	    O(NlogN) for random piot, O(1) time
Heap Sort- O(NlogN) time, O(N) space


