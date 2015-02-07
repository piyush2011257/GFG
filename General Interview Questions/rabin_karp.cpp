/*
http://www.geeksforgeeks.org/searching-for-patterns-set-3-rabin-karp-algorithm/

Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.

Examples:
1) Input:

  txt[] =  "THIS IS A TEST TEXT"
  pat[] = "TEST"

Output:

Pattern found at index 10

2) Input:

  txt[] =  "AABAACAADAABAAABAA"
  pat[] = "AABA"

Output:

   Pattern found at index 0
   Pattern found at index 9
   Pattern found at index 13

The Naive String Matching algorithm slides the pattern one by one. After each slide, it one by one checks characters at the current shift and if all characters match then prints the match.
Like the Naive Algorithm, Rabin-Karp algorithm also slides the pattern one by one. But unlike the Naive algorithm, Rabin Karp algorithm matches the hash value of the pattern with the hash value of current substring of text, and if the hash values match then only it starts matching individual characters. So Rabin Karp algorithm needs to calculate hash values for following strings.

1) Pattern itself.
2) All the substrings of text of length m.

Since we need to efficiently calculate hash values for all the substrings of size m of text, we must have a hash function which has following property.
Hash at the next shift must be efficiently computable from the current hash value and next character in text or we can say hash(txt[s+1 .. s+m]) must be efficiently computable from hash(txt[s .. s+m-1]) and txt[s+m] i.e., hash(txt[s+1 .. s+m])= rehash(txt[s+m], hash(txt[s .. s+m-1]) and rehash must be O(1) operation.

The hash function suggested by Rabin and Karp calculates an integer value. The integer value for a string is numeric value of a string. For example, if all possible characters are from 1 to 10, the numeric value of “122” will be 122. The number of possible characters is higher than 10 (256 in general) and pattern length can be large. So the numeric values cannot be practically stored as an integer. Therefore, the numeric value is calculated using modular arithmetic to make sure that the hash values can be stored in an integer variable (can fit in memory words). To do rehashing, we need to take off the most significant digit and add the new least significant digit for in hash value. Rehashing is done using the following formula.

hash( txt[s+1 .. s+m] ) = ( d ( hash( txt[s .. s+m-1]) – txt[s]*h ) + txt[s + m] ) mod q

hash( txt[s .. s+m-1] ) : Hash value at shift s.
hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1)
d: Number of characters in the alphabet
q: A prime number
h: d^(m-1)

How to choose value of q ( prime number ) ?
    d is the number of characters in alphabet
    q is modulus
then "dq" should be representable in the available word size
Because in- hash( txt[s+1 .. s+m] ) = ( d ( hash( txt[s .. s+m-1]) – txt[s]*h ) + txt[s + m] ) mod q
func(s,s+m-1) is %q and hence < q
and for func(s+1,s+m) we do (d*func(s,s+m-1) )%q and hence "dq" must fit in integer chosen

The average and best case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm). Worst case of Rabin-Karp algorithm occurs when all characters of pattern and text are same as the hash values of all the substrings of txt[] match with hash value of pat[]. For example pat[] = “AAA” and txt[] = “AAAAAAA”
*/

#include<cstdio>
#include<cstring>
using namespace std;

bool is_match ( char *str, char *pat, int i );
void rabin ( char *str, char *pat, int n1, int n2);

const int q= 257, d=256;
int main()
{	char str[]="AABAACAADAABAAABAA";
	char pat[]="AABA";
	int n1=strlen(str);
	int n2=strlen(pat);
	if ( n1 >= n2 )
		rabin(str, pat, n1, n2);
	else
		printf("Input string is shorted than pattern\n");
	return 0;
}


void rabin ( char *str, char *pat, int n1, int n2)
{	int h=1;
	for ( int i=0; i<n2-1; i++ )
	{	h=h*d;
		h=h%q;
	}
	int txt=0, pt=0;
	/*
	Initial hash function
	func(i+1, i+m) = ( d * ( func(i,i+m-1) ) + str[i+m-1] ) %q
	*/
	for ( int i=0; i<n2; i++ )
	{	txt= ( d * ( txt ) + str[i] )%q;
		pt= ( d * ( pt ) + pat[i] )%q;
		if ( txt < 0 )				// if modulo becomes negative. COrner case- Modular Arithmetic
			txt+=q;
		if ( pt < 0 )
			pt+=q;
	}
	if ( txt == pt && is_match(str,pat,0 ) )
		printf("0 %d\n",n2-1);
	for ( int i=1; i+n2 <= n1; i++ )
	{	/*
		Hash function for processing
	        func(i+1, i+m) = ( d * ( func(i,i+m-1) - str[i]*h ) + str[i+m-1] ) %q
		*/
		txt = ( d * ( txt - str[i-1]*h ) + str[i+n2-1] )%q;
		if ( txt < 0 )
			txt += q;
		if ( txt == pt && is_match ( str,pat,i) )
			printf("%d %d\n",i,i+n2-1);
	}
}

bool is_match ( char *str, char *pat, int i )
{	while ( *pat != '\0' && *pat == *(str+i) )
			i++, pat++;
	if ( *pat == '\0' )
		return 1;
	return 0;
}
