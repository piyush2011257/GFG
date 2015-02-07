http://www.geeksforgeeks.org/amazon-interview-experience-set-167-sde-1-year-6-months-experience/
Outlook:
A server receives meeting objects from multiple senders. Meeting object contains meeting time, sent time, recipient(s), sender id,etc. When recipient comes and checks the server, he/she should get requests based on meeting time and not based on sent time. Many discussions on space complexity and time complexity.
Eg:

12 PM      From: A  To: B,C,D   meeting time: 4 PM   meeting Id: 1
12.30 PM   from: A  To C,D      meeting time : 2 PM   meeting Id:2
1:PM       From B   To: C       meeting time: 1.30PM  meeting Id:3

When C requests the server, C should get ID3 as 1st, ID2 as 2nd and ID1 as 3rd meeting.


Method 1
Use Hashing + Bucket 
map<string, node *>
We can maintain bucket using AVL Tress

SO we use receiver as Hashing Key, store each record on the bais of meeting time using AVL Tree
O(logN) insert
O(N) display
O(1) Hashing

Implementing Hashing- using normal string method or using trie
Using Trie for hashing + Bucket using AVL

Most efficient way is AVL for maintaining balanced BST

