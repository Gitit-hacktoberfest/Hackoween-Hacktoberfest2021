#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head=NULL;

void create();
void findLoopHead();

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

void findLoopHead()
{
	struct node *slow=head, *fast=head;
	slow=slow->next;
	fast=fast->next->next;
	
	while(fast && fast->next)
	{
		if(slow==fast)
			break;
		slow=slow->next;
		fast=fast->next->next;
	}

	if(slow!=fast)
	{
		printf("Ooops, no loop\n");
		return;
	}
	slow=head;
	while(slow!=fast)
	{
		slow=slow->next;
		fast=fast->next;
	}
	printf("%d",slow->data);
}

int main()
{
	create();
	struct node* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=head->next->next;
	//The above code creates a loop in the Singly Linked List
	findLoopHead();
  //The time complexity is O(n), where n is the number of nodes in the Singly Linked List
  //The space complexity is O(1)
}
