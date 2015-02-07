/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-149-campus-internship/
You are given a phone keypad like following diagram, where each character corresponds to a digit mentioned in the same box.You are given n strings and you have to find their decimal representation. You have to print the string and corresponding decimal representation in descending order. For example, if you are given “amazon” then its corresponding decimal notation will be 262966. If more than one strings have same decimal notation then you have to print them in the order in which input is given. The given string consists of lower case alphabets only.


Algorithm is use a map -> map[character]=decimal
Now store a node
{	char word;
	char representation_in_decimal;
}

sort the node array on the basis of word and print in descending order
O(NlogN*L) -> Sorting

Number of characters = Length of i/p string
*/
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

struct nod
{	char word[100];
	char representation[100];
};

bool cmp ( nod n1, nod n2 );

int main()
{	char val[27]="22233344455566677778889999";
	char ch[100];
	int n;
	scanf("%d",&n);
	nod node[n];
	for ( int i=0; i<n; i++ )
	{	scanf("%s",ch);
		//ch=tolower(ch);
		strcpy(node[i].word,ch);
		int j;
		for ( j=0; ch[j] != '\0'; j++ )
			node[i].representation[j]=val[ch[j]-'a'];
		node[i].representation[j]='\0';
		
	}
	sort(node, node+n, cmp);
	// O(NlogN*L)
	for ( int i=n-1; i>=0; i-- )
		printf("%s %s\n", node[i].representation, node[i].word);
	return 0;
}
		
bool cmp ( nod n1, nod n2 )
{	int l1=strlen(n1.representation);
	int l2=strlen(n2.representation);
	int i;
	for ( i=0; i<l1 && i < l2; i++ )
		if ( n1.representation[i] < n2.representation[i] )
			return 1;
		else if ( n1.representation[i] > n2.representation[i] )
			return 0;
	if ( l1 <= l2 )
		return 1;
	else
		return 0;
}
	

