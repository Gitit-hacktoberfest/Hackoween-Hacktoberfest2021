#include<stdio.h>
#include<stdlib.h>

void create();
void reverseIter();
void display();

struct node
{
	int data;
	struct node *next;
};

struct node *head=NULL;

void reverseIter()
{
	struct node *prev=NULL, *next=NULL, *curr=head;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	head=prev;
}

struct node* reverseRec(struct node *first)
{
	if(first==NULL || first->next==NULL)
		return first;
	struct node *revHead=reverseRec(first->next);
	first->next->next=first;
	first->next=NULL;
	return revHead;
}

void display()
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void create()
{
	printf("Enter the element to be inserted or press -1 to end\n");
	int n;
	scanf("%d",&n);
	while(n!=-1)
	{
		struct node *newNode=(struct node*)malloc(sizeof(struct node));
		newNode->data=n;
		newNode->next=NULL;
		if(head==NULL)
			head=newNode;
		else
		{
			struct node *temp=head;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=newNode;
		}
		printf("Enter the element to be inserted or press -1 to end\n");
		scanf("%d",&n);
	}
}

int main()
{
	create(); // create a Singly Linked List
	display();
	reverseIter(); // reverse using iteration
  // Time complexity is O(n), where n is the number of nodes
  // Space complexity is O(1)
	display();
	head=reverseRec(head); // reverse using recursion
  // Time complexity is O(n), where n is the number of nodes
  // Space complexity is O(n), where n is the number of nodes
	display();
}
