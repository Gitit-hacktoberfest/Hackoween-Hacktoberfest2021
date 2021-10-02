#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct LinkedList
{
	struct node* head;
	struct node* tail;
};

struct LinkedList* createSingleLinkedList(int value)
{
	struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	list->head = (struct node*)malloc(sizeof(struct node));
	list->tail = (struct node*)malloc(sizeof(struct node));
	struct node* first = (struct node*)malloc(sizeof(struct node));
	first->data = value;
	first->next = NULL;
	list->head = first;
	list->tail = first;
	
	return list;
}

struct Stack
{
	struct LinkedList* list;
};

struct Stack* createStack(int value)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->list = createSingleLinkedList(value);
	
	return stack;
}

void push(struct Stack* stack , int value)
{
	struct node* current = (struct node*)malloc(sizeof(struct node));
	current->data = value;
	current->next = stack->list->head;
	stack->list->head = current;
}

int isEmpty(struct Stack* stack)
{
	if(stack->list->head == NULL) {
		return 1;
	}
	return 0;
}

int pop(struct Stack* stack)
{
	if(isEmpty(stack)) {
		printf("Stack is empty.");
		return -1;
	}
	else {
		struct node* temp = stack->list->head;
		stack->list->head = temp->next;
		return temp->data;
	}
}

int peek(struct Stack* stack)
{
	if(isEmpty(stack)) {
		printf("Stack is empty.");
		return -1;
	}
	else {
		return stack->list->head->data;
	}
}

void deleteStack(struct Stack* stack)
{
	stack->list->head = NULL;
	stack->list->tail = NULL;
}

int main()
{
	struct Stack* stack = createStack(1);
	push(stack, 2);
	push(stack, 3);
	
	printf("%d\n", pop(stack));
	printf("%d\n", peek(stack));
	printf("%d\n", pop(stack));
	
	return 0;
}
