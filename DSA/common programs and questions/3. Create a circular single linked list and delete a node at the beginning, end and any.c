#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node *next;
}*Head;

void create(int A[],int n)
{
int i;
struct Node *t,*last;
Head=(struct Node*)malloc(sizeof(struct Node));
Head->data=A[0];
Head->next=Head;
last=Head;
for(i=1;i<n;i++)
{
t=(struct Node*)malloc(sizeof(struct Node));
t->data=A[i];
t->next=last->next;
last->next=t;
last=t;
}
}
void Display(struct Node *h)
{
do
{
printf("%d ",h->data);
h=h->next;
}while(h!=Head);

printf("\n");
}
void RDisplay(struct Node *h)
{
static int flag=0;
if(h!=Head || flag==0)
{
flag=1;
printf("%d ",h->data);
RDisplay(h->next);
}
flag=0;
}
int Length(struct Node *p)
{
int len=0;
do
{
len++;
p=p->next;
}while(p!=Head);
return len;
}
int Delete(struct Node *p,int index)
{
struct Node *q;
int i,x;
if(index <0 || index >Length(Head))
return -1;
if(index==1)
{
while(p->next!=Head)p=p->next;
x=Head->data;
if(Head==p)
{
free(Head);
Head=NULL;
}
else

{
p->next=Head->next;
free(Head);
Head=p->next;
}
}
else
{
for(i=0;i<index-2;i++)
p=p->next;
q=p->next;
p->next=q->next;
x=q->data;
free(q);
}
return x;
}
int main()
{
int arr[100],i,n; 
    printf("Enter the size of the array\n");  
    scanf("%d",&n);  
    printf("Enter the elements of the array\n");  
    for(i = 0; i<n; i++)  
    {  
        scanf("%d",&arr[i]);  
    } 
create(arr,n);
printf("\nSelect from the following Deleting options\n");
                 	printf("1. At Beginning\n2. At End\n3. After a Node\n");
                 	int choice;
                    scanf("%d",&choice);
                    switch(choice)
                    {
                       case 1: 	Delete(Head,1);
                                RDisplay(Head);
                       		break;
                       case 2: 	Delete(Head,n);
                                RDisplay(Head);
                       		break;
                       case 3: 	printf("Enter the location  which you want to delete: ");
                            int location ;
                       		scanf("%d",&location);
                       		Delete(Head,location);
                       		RDisplay(Head);
                       		break;
                       default: printf("\nPlease select correct Inserting option!!!\n");
                    }
                 }
/* Time complexity:O(n)
  Space complexity:O(n) */
