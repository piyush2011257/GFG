162- R4_Q1
165- R4_Q1
String- Duplicate / COmpare / ANagram
External Sorting + Inplace Sort
External Sorting + Hashing
Hashing - Hash functions-	Sorted alphabets
				Each alphabet represents a prime 26th alphabet is 101. Use %1000000007 and use hashing collision resolution
				Count of letters
Trie / TST

http://www.geeksforgeeks.org/amazon-interview-experience-set-165-sde/
Given a word and the dictionary, find all the anagrams of the particular word present in dictionary (That are valid words). Propose the data structure you have used and time complexity of the solution.

http://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/
http://stackoverflow.com/questions/12477339/finding-anagrams-for-a-given-word
http://stackoverflow.com/questions/11108541/get-list-of-anagrams-from-a-dictionary
http://www.quora.com/What-algorithms-and-data-structures-can-be-used-to-find-anagrams
http://www.quora.com/I-have-a-list-of-thousands-of-words-Now-i-want-to-store-these-words-in-such-a-way-that-I-will-be-able-to-find-all-anagrams-for-a-given-string-from-this-dictionary-with-minimum-complexity

Method 1
Using Hashing
Sort each word and use it as a hash key and check
O(n) time

Map each word to the string of its sorted letters. Let's call this sorted string the word's "signature". Examples:

teal => aelt
tale => aelt
late => aelt
fate => aeft

Now if you invert the map, you get all of the words with a given "signature". So a signature of "aelt" corresponds to the words "teal", "tale", "late", etc. There aren't that many words in the English dictionary, so storing this entire mapping in memory would only take a few megabytes of RAM.


Method 2-
The obvious solution is to map each character to a prime number and multiply the prime numbers. So if 'a'' -> 2 and 'b' -> 3, then
    'ab' -> 6
    'ba' -> 6
    'bab' -> 18
    'abba' -> 36
    'baba' -> 36

To minimise the chance of overflow, the smallest primes could be assigned to the more frequent letters (e,t,i,a,n). Note: The 26th prime is 101.

And we can use % 1000000007 and use hash collision resolution techniques

Method 1- Hashing function is using key as sorted characters and Method 2 is using product of characters as the key / hash function

Method 3-
One possible hash function could be (assuming english words only) a sorted count of the number of occurrences of each letter. So for "anagram" you would generate [('a', 3), ('g', 1), ('n', 1), ('m', 1), ('r',1)].

All the solutions revolve around hashing but use different hash functions

Above all for getting list of all anagrams in a file
QUESTION says find anagrams of a given word-> we can use Method 3 -> occurence based schema ( 26 letters - case insensitive English letters )
O(1) space and O(N) COMPLEXITY

int occ[26]={0}
char ch[L]=input_string
for ( i=0->L-1}
	occ[ch[i]-'a']++;
now for each word 
	L'= strlen(word)
	for ( i=0->L'-1}
		occ'[ch[i]-'a']++;
	compare occ[] and occ[]
	if same the anagram else not an anagram


Alternatively -> sort / multiply using primes

Method 4-
Using Trie / TST
for each word -> sort and make TST / Trie
No need of hashing
During insertion, if is_Word == 1 -> anagram else not an anagram and insert / mark is_word=1
Max length of word <<<< Number of words
