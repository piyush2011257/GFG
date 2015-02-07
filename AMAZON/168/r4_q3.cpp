http://www.geeksforgeeks.org/amazon-interview-experience-set-168/

In an auctioning system, the bidder with the highest bid wins but charged at kth highest price. Develop a system for it. Solved it using a hashmap. Was asked to write a code for the same.

Find kth highest bid -> use min_heap of size k !!!

Maintain a min-heap of size k
Find k largest elements using heap. heap[0] -> kth largest element
O(NlogK)- building heap

O(logK) - ammortized

O(n)- using selection of selection for finding kth largest element

if k == n
O(NlogN)

Dynamically we can get the value

Alternatively, we can use BST / AVL Tree for storing records-
O(N^2)- build tree O(N), O(K)- find highest bidder and kth highest bid
O(NlogN)- build tree O(logN), O(K) - finding highest bidder and highest bid
