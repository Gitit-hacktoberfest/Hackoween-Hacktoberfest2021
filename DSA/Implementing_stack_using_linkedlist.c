#include <stdio.h>

#include <stdlib.h>

struct node

{

int info;

struct node *ptr;

}*top,*top1,*temp;

int topelement();

void push(int data);

void pop();

void empty();

void display();

void destroy();

void stack_count();

void create();

int count = 0;

void main()

{

int no, ch, e;
// Choices 
printf("\n 1 - Push");

printf("\n 2 - Pop");

printf("\n 3 - Top");

printf("\n 4 - Empty");

printf("\n 5 - Exit");

printf("\n 6 - Dipslay");

printf("\n 7 - Stack Count");

printf("\n 8 - Destroy stack");

create();

while (1) // when condition is true

{

printf("\n Enter choice : "); 

scanf("%d", &ch);

switch (ch)

{

case 1:

printf("Enter data : "); 

scanf("%d", &no);

push(no); // to add data

break;

case 2:

pop();  // to delete data

break;

case 3:

if (top == NULL) // to check if stack is empty

printf("No elements in stack");

else

{

e = topelement();

printf("\n Top element : %d", e);

}

break;

case 4:

empty(); // top element in stack

break;

case 5:

exit(0); // exit i.e close program 

case 6:

display(); // display elements in stack

break;

case 7:

stack_count(); // to count no of data in stack 

break;

case 8:

destroy(); // to delete stack

break;

default :

printf(" Wrong choice, Please enter correct choice ");

break;

}

}

}
// creating stack 
void create()

{

top = NULL;

}
// counting no of elements in stack
void stack_count()

{ 

printf("\n No. of elements in stack : %d", count);

}
// saving data in stack
void push(int data)

{

if (top == NULL)

{

top =(struct node *)malloc(1*sizeof(struct node));

top->ptr = NULL;

top->info = data;

}

else

{

temp =(struct node *)malloc(1*sizeof(struct node));

temp->ptr = top;

temp->info = data;

top = temp;

}

count++;

}
// display data in stack
void display()

{

top1 = top;

if (top1 == NULL)

{

printf("Stack is empty");

return;

}

while (top1 != NULL)

{

printf("%d ", top1->info);

top1 = top1->ptr;

}

}
// delete data in stack 
void pop()

{

top1 = top;

if (top1 == NULL)

{

printf("\n Error : Trying to pop from empty stack");

return;

}

else

top1 = top1->ptr;

printf("\n Popped value : %d", top->info);

free(top);

top = top1;

count--;

}

int topelement()

{

return(top->info);

}

void empty()

{

if (top == NULL)

printf("\n Stack is empty");

else

printf("\n Stack is not empty with %d elements", count);

}
// delete whole stack
void destroy()

{

top1 = top;

while (top1 != NULL)

{

top1 = top->ptr;

free(top);

top = top1;

top1 = top1->ptr;

}

free(top1);

top = NULL;

printf("\n All stack elements destroyed");

count = 0;

}





// time complexity
// Push: O(1)
// Pop: O(1)
// Top: O(1)
// space complexity: O(n)
