http://www.geeksforgeeks.org/amazon-interview-experience-set-142-campus-sde-1/
Given very large number of empty crates of varying sizes, we need to find the best fit crate for the given item and allocate it. Need to design a data structure for this scenario. Operations involved:
    Insert a crate
    Search the best fit crate
    Delete the crate after allocating it.
e.g. 3 crates of weight 10, 20 and 30 are there. An item of size 15 appears then we’ll allocate crate of size 20 and delete it.
Sol. Use binary search tree (balanced using red-black criteria or any) and implement ceil function.
All operations will be O (log(n)).
Q2. Optimize above data structure for weekends where amazon have lots of crates but very less search operations.

1st method-
Sorted DLL
Search- O(N)
Insert- O(N)
Delete- O(N)

How to improve??
Using 2 heaps- O(NlogN)
FInding best fit by poppin and then re-inserting again popped elements. O(NlogN)

2nd method-
Balanced Binary Tree- AVL and implement ceil operation
Search- O(logN)
Insert- O(logN)
Delete- O(logN)

