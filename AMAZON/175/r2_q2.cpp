/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-175-sde/

There are millions of string in the database. How would you store them for efficient searching. You also need to print all anagrams together many times, now how would you store them and insert if a new string is added to database ?
*/


Trie Structure
Search / Insert / Delete - O(L) 	L- max length of the word

Now for anagrams?
i/p words-

cat
tac

cat -> act -> insert in trie with is_word -> actual word (cat)
tac -> act -> insert in trie with is_word -> actual word (tac)

a	c	t ( is_word[cat]=1 )
		  ( is_word[tac]=1 )

bool is_word -> map<string,bool> is_word

Print ALL possible anagrams -> traversal of the trie- O(N*L)	N- number of words
Print all anagrams of a given word -> O(L) + O(A) 	A- max no. of anagrams of a given word

Space
char ch;
char *ptr[26]
map<string,bool>is_word

extra 26 pointers per node

Trie -> TST
char ch;
char *left, *eq, *right;
map<string,bool>is_word
Space optimized
