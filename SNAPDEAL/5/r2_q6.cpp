#include<stdio.h>
#include<stdlib.h>
 
struct node
{	int data;
 	struct node* next;
};
 
void removeLoop(struct node *, struct node *);
 
int detectAndRemoveLoop(struct node *list)
{	struct node  *slow_p = list, *fast_p = list;
 	while (slow_p && fast_p && fast_p->next)		// fast_p->next = NULL means  no loop
    	{	slow_p = slow_p->next;
        	fast_p  = fast_p->next->next;
        	if (slow_p == fast_p)
        	{	removeLoop(slow_p, list);
            		return 1;
        	}
    	}
    	return 0;
}
 
void removeLoop(struct node *loop_node, struct node *head)
{	struct node *ptr1 = loop_node;
 	struct node *ptr2 = loop_node;
    	unsigned int k = 1, i;
    	while (ptr1->next != ptr2)
    	{	ptr1 = ptr1->next;
        	k++;
    	}
    	ptr1 = head;
    	ptr2 = head;
    	for(i = 0; i < k; i++)
      		ptr2 = ptr2->next;
    	while(ptr2 != ptr1)
    	{	ptr1 = ptr1->next;
        	ptr2 = ptr2->next;
    	}
    	ptr2 = ptr2->next;
    	while(ptr2->next != ptr1)
       		ptr2 = ptr2->next;
 	ptr2->next = NULL;
}
 
void push(struct node** head_ref, int new_data)
{	struct node* new_node = (struct node*) malloc(sizeof(struct node));
    	new_node->data  = new_data;
    	new_node->next = (*head_ref);
    	(*head_ref)    = new_node;
}
 
void printList(struct node *node)
{	while(node != NULL)
 	{ 	printf("%d  ", node->data);
        	node = node->next;
	}
}
 
int main()
{	struct node* head = NULL;
    	push(&head, 10);
    	push(&head, 4);
    	push(&head, 15);
    	push(&head, 20);
    	push(&head, 50);
    	head->next->next->next->next->next = head->next->next;
    	detectAndRemoveLoop(head);
    	printf("Linked List after removing loop \n");
    	printList(head);
    	return 0;
}
