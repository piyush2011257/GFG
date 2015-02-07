http://www.geeksforgeeks.org/amazon-interview-experience-set-165-sde-2/

Given a huge file with large number of words, code a function that would take a word as input and print all anagrams of that word present in the file as output. Function has to be really really fast alsmo O(1) run time. You are allowed to take as much time and resources for pre processing the file once. But after pre-processing function should perform in O(1) time.

<Use hashmap, and fact that all anagrams have similar alphabetical order of letters>
Create a hash function for above.
He then asked, another way instead of Hash ?
How to optimize searching among this linked list of heads of other linked lists.

Method 1-
Use Hash Maps
map < string, vector<string>>
where key is the sorted ordering of alphabets and vector<string> contains all the anagrams
O(LlogL) - Sorting word assuming max length of word be L

Hashing function ->
key = sorted alphabets
hash(key)
	( (key[i]-'z')*i )% size	<- -> ( ASCII value of char - ASCII of 'a' ) * position of character ) % size 
	Size should be prime number preferably

CAT -> ACT

hash("ACT")
	(0*0 + 2*1 + 19*2)%size

Dynamic Re-sizing / Shrinking

Another function for hashing
a-'1' b='2' c='3' d='5' e='7'
all characters == ith prime number
Hash value = ( product of alphabets in prime representation ) % size ( size is preferably prime )

Method 2
Using Trie struture to create a kind of hash

word	sorted
CAT	act
CAR	acr
TAC	act
CATT	actt
TACT	actt



A	C	T		T
		|		|
		cat, tac	catt, tact

		R
		|
		car

struct trie 
{	trie *next[26];
	list *next;
	char ch;
}

next != NULL == is_word ==1
list *next -> list of words in dictionary

Alternate way of implementing Hashing

Further space optimization
Trie -> TST

struct tst
{	tst *left, *eq, *right;
	list *next;
	char ch;
}

			A
			|
			C
			|
	    car <- R -- T -> cat, act
			|
			T -> catt, tact

Hashing function uses trie structure

Now to get all anagrams in both Methods is trivial
