/*
http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
Input:

  txt[] =  "AABAACAADAABAAABAA"
  pat[] = "AABA"

Output:

   Pattern found at index 0
   Pattern found at index 9
   Pattern found at index 13

The KMP matching algorithm uses degenerating property (pattern having same sub-patterns appearing more than once in the pattern) of the pattern and improves the worst case complexity to O(n). The basic idea behind KMP’s algorithm is: whenever we detect a mismatch (after some matches), we already know some of the characters in the text (since they matched the pattern characters prior to the mismatch). We take advantage of this information to avoid matching the characters that we know will anyway match.
KMP algorithm does some preprocessing over the pattern pat[] and constructs an auxiliary array lps[] of size m (same as size of pattern). Here name lps indicates longest proper prefix which is also suffix.. For each sub-pattern pat[0…i] where i = 0 to m-1, lps[i] stores length of the maximum matching proper prefix which is also a suffix of the sub-pattern pat[0..i].

   lps[i] = the longest proper prefix of pat[0..i] 
              which is also a suffix of pat[0..i]. 

Examples:
For the pattern “AABAACAABAA”, lps[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]
For the pattern “ABCDE”, lps[] is [0, 0, 0, 0, 0]
For the pattern “AAAAA”, lps[] is [0, 1, 2, 3, 4]
For the pattern “AAABAAA”, lps[] is [0, 1, 2, 0, 1, 2, 3]
For the pattern “AAACAAAAAC”, lps[] is [0, 1, 2, 0, 1, 2, 3, 3, 3, 4]

Searching Algorithm:
Unlike the Naive algo where we slide the pattern by one, we use a value from lps[] to decide the next sliding position. Let us see how we do that. When we compare pat[j] with txt[i] and see a mismatch, we know that characters pat[0..j-1] match with txt[i-j+1…i-1], and we also know that lps[j-1] characters of pat[0…j-1] are both proper prefix and suffix which means we do not need to match these lps[j-1] characters with txt[i-j…i-1] because we know that these characters will anyway match.

Preprocessing Algorithm:
In the preprocessing part, we calculate values in lps[]. To do that, we keep track of the length of the longest prefix suffix value (we use len variable for this purpose) for the previous index. We initialize lps[0] and len as 0. If pat[len] and pat[i] match, we increment len by 1 and assign the incremented value to lps[i]. If pat[i] and pat[len] do not match and len is not 0, we update len to lps[len-1].
*/
#include<cstdio>
#include<cstring>
using namespace std;

void preprocess ( char *pat, int n2, int *lps );
void kmp ( char *str, char *pat, int n1, int n2 );

int main()
{	char str[]="AABAACAADAABAAABAA";
	char pat[]="AABA";
	int n1=strlen(str);
	int n2=strlen(pat);
	kmp(str,pat,n1,n2);
	return 0;
}

void kmp ( char *str, char *pat, int n1, int n2 )
{	int lps[n2];
	preprocess(pat,n2,lps);
	for ( int i=0; i<n2; i++ )
		printf("%d ", lps[i]);
	printf("\n");
	int i=0;
	if ( n1 < n2 )
	{	printf("Pattern is longer than string\n");
		return;
	}
	for ( int s=0,p=0; s<n1;  )
	{	if ( str[s] == pat[p] )
		{	s++;
			p++;
			if ( p == n2 )
			{	printf("String found!! %d %d\n", s-n2, s-1);
				p=lps[p-1];
			}
		}
		else		
		{	if ( p != 0 )
				p=lps[p-1];
			else
				s++;
		}

	}
}

void preprocess ( char *pat, int n2, int *lps )
{	lps[0]=0;
	for ( int i=1; i<n2; i++ )
		if ( pat[i] == pat[lps[i-1]] )
			lps[i]=lps[i-1]+1;
		else
			lps[i]=0;
}
