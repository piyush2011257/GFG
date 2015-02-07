/*
http://www.geeksforgeeks.org/amazon-interview-questions-set-147/
Guys this question brainf**cked me.The question was based on “20 question game”.I never played this game. This was the actual question-

Given a set of words like Modi,MJ,Obama,Hillary Clinton.We need to create a intelligent computer game so that it will popup minimum questions to find out the answer the player thought. For ex- If give user choices to chose any word from Modi,MJ,Obama,Hillary Clinton.Now computer will show popup from any of the tags.Like if user chose Modi then in this case computer should ask minimum questions to find out what will be the guess.so in this case computer only askd “PM” tag and computer will show the popup “Modi”. 

http://www.geeksforgeeks.org/forums/topic/20-questions-game/
This is basically what I have to do:

The program begins with minimal knowledge about animals: It knows that cats have legs and snakes do not. When the program incorrectly guesses snake the next time, it asks for the answer and also for a way to distinguish between snakes and earthworms.

The program builds a binary tree of questions and guesses (in this case, animals). The data in each TreeNode (a class you will define) is a String that represents either a question or a guess. Guesses are stored in the leaf nodes, while all other nodes contain questions with known yes/no answers. A YES response to a question is store in the question’s left child, and a NO response is stored in the question’s right child. During the course of the interaction with the user you need to walk down the tree asking questions and taking the right branch until reaching a guess node. Make the guess, and if necessary, update the tree based on the user’s response.

Comment: Let us illustrate how to envision the corresponding tree for the example above. In the beginning, this tree has the following form:

Does it have legs?
//////// \
/////// \
Is it a cat? Is it a snake?

According to the assignment, once we are in the node, the user’s answer YES leads to the left child, while the answer NO leads to the right child.
When we are in a leaf, the answer YES leads to the computer’s happy statement “I win! Continue?”, while the answer NO triggers a computer response “I give up. What is it?”

After the user answered NO to the question “Is it a snake?”, the computer asks the user for the new animal (earthworm) and a new question that helps distinguish snakes from earthworms. With this new information in place, the tree takes the following new form:

Does it have legs?
/ \
/ \
Is it a cat? Does it live underground?
/ \
/ \
Is it an earthworm? Is it a snake?
When the user guesses a fish, the computer adds fish as a new object prompted by the user and a new question to distinguish between fishes and snakes:
Does it have legs?
/ \
/ \
Is it a cat? Does it live underground?
/ \
/ \
Is it an earthworm? Does it live in water?
/ \
/ \
Is it a fish? Is it a snake?
and so on.
*/
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

struct node
{	node *left, *right;
	string question, answer;
	node()
	{	left=right=NULL;	}
};

void func ( node *root );

int main()
{	node *root=NULL;
	string question, yes, no, yes_char;
	printf("There is no data and tag.\nEnter question and then 2 people ( first for Y and then for N )\n");
	cin>>question>>yes_char>>yes>>no;
	root=new node();
	root->question=question;
	root->answer=yes_char;
	root->left=new node();
	root->right=new node();
	root->left->answer=yes;
	root->right->answer=no;
	while ( 1 )
	{	printf("Start the game\n");
		func(root);
		printf("\n");
	}
	return 0;
}

void func ( node *root )
{	if ( root->left != NULL && root->right != NULL )
	{	string ans;
		cout<<root->question<<endl;
		cin>>ans;
		if ( ans.compare(root->answer) == 0  )
			func(root->left);
		else
			func(root->right);
	}
	else
	{	cout<<"My answer is "<<root->answer<<endl;
		string ans, user, question;
		cout<<"Correct (Y/N)"<<endl;
		cin>>ans;
		if ( ans.compare("y") == 0 || ans.compare("Y") == 0 )
			return;
		cout<<"Enter question, characterstic and new person. Y for the user and N for the computer generated answer"<<endl;
		cin>>question;
		cin>>ans;
		cin>>user;
                root->right=new node();
                root->right->answer=root->answer;
		root->question=question;
		root->answer=ans;
		root->left=new node();
		root->left->answer=user;
	}
}

/*
Sample I/P-
Male/Female
Male
Modi
Clinton
Male
N
India/US
US
Obama
Male
India
Y
Male
US
Y
Male
US
N
Politics/Art
Art
MJ
Male
US
Politics
Y
Male
US
Arts
Y
*/
