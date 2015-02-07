http://www.geeksforgeeks.org/amazon-interview-questions-set-146/
Given two valid dictionary words, find the minimum number of steps required to transform first word to second word. Following are the transformation rules –

1. You can, in a single step, change a single letter in the word.
2. Each transition should result in a valid word. Assume you have been provided a helper function boolean isValid (String word) which tells you if a word is valid or not.
3. This must be done with minimum transitions.

Example: Transform CAT to TOY. One of the several possible transformations is CAT -> CAR -> TAR -> TOR -> TOY

https://www.quora.com/Given-a-source-string-and-a-destination-string-write-a-program-to-display-sequence-of-strings-to-travel-from-source-to-destination-Can-you

This is a BFS. My code assumes all strings are lowercase.

Brief explanation of what my code is doing: for any given word, I find a word that is edit distance 1 from that word and construct a tree of these words, associating each word with some parent. I then BFS through all words that I am able to construct. If the BFS yields that the goal word cannot be reached, then we return null to indicate that it is impossible. Otherwise, we start at the goal word and travel up the parent words to get the full sequence.

Solution

Queue q;
q.push(start);
parent.push(start)			// parent stores all words that have been traversed so far to avoid loop and re-solving solved words
while ( q.empty() == 0 )
{	str=q.pop();
	if ( str == end_string )
		break;
	if ( str == NULL )			// level differentiator / tranformation count increment
		level++;
		q.push(NULL);
	for ( int i=0; i<L-1; i++ )
	{	for ( ch={a,b,c,d,.....x,y,z}
			str'=str(0,i-1)+ch+str(i+1,L-1)
			if ( str' is_valid and parent() doesn not contain str' )
				q.push(str')
				parent.push(str')
	}
}

print(level+1) -> minimum number of transformations

let dict be
CAT
CAR
CAN
COT
COW
TAR
TAN
TAT
TEA
TOY
TOR



WORD POPPED	QUEUE		PARENT/VISITED
		CAT		CAT
		NULL
		TAT		TAT
		COT		COT
		CAN		CAN				<- each level contains only 1 tranformation from previous level string
		CAR		CAR
		NULL		
		TAR		TAR
		TAN		TAN
		COW		COW
		NULL
		TOR		TOR
		NULL	
		TOY		TOY

4 TIMES NULL ENCOUNTERED -> 4 TIMES LEVEL++
LEVEL INITIALLY =
SO LEVEL=4
-> MINIMUM NUMBER OF TRANSFORMATION
TOY <- TOR <- TAR <- CAR <- CAT

4 TRANFORMATIONS

O(WORDS IN DICTIONARY)
SINCE EACH WORD IS TRAVERSED ONCE ONLY
