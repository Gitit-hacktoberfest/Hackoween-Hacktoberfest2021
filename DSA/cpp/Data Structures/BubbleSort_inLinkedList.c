#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
    };
    struct node*head;

void bubblesort();
void swap(struct node *a, struct node *b);

int main(){
    int n;
    struct node*current,*prev;
    printf("\n\nEnter no of nodes : ");
    scanf("%d",&n);
    printf("Enter the values : ");
    for(int i = 0;i<n;i++){
        current = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&current->data);
        current->next = NULL;
        if(head==NULL){
            head = current;
        }
        else
        prev->next=current;
        prev=current;
    }    

    bubblesort();

    struct node *temp1 = head;
    printf("The sorted values are : ");
    while(temp1 !=NULL){
        printf("%d ",temp1->data);        
        temp1 = temp1->next;
    }
    printf("\n\n");
}
void bubblesort(){
    struct node *s = head;
    int swapped, i;
	struct node *ptr1=head;
	struct node *lptr = NULL;	
	if (s == NULL)
		return;
	while(swapped)
	{
		swapped = 0;
		ptr1 = s;
		while (ptr1->next != lptr){
			if (ptr1->data > ptr1->next->data)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
	
}
void swap(struct node *a, struct node *b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}
