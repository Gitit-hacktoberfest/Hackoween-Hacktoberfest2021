#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	int top;
	int size;
	int* arr;
};

struct Stack* createStack(int capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->size = capacity;
	stack->arr = (int *)malloc(capacity*sizeof(int));
	
	return stack;
}

int isEmpty(struct Stack* stack)
{
	if(stack->top == -1) {
		return 1;
	}
	return 0;
}

int isFull(struct Stack* stack)
{
	if(stack->top == stack->size - 1) {
		return 1;
	}
	return 0;
}

void push(struct Stack* stack, int data)
{
	if(isFull(stack)) {
		printf("The stack is full.");
	}
	else {
		stack->arr[++stack->top] = data;
	}
}

int pop(struct Stack* stack)
{
	if(isEmpty(stack)) {
		printf("The stack is empty.");
		return -1;
	}
	return stack->arr[stack->top--];
}

int peek(struct Stack* stack)
{
	if(isEmpty(stack)) {
		printf("The stack is empty.");
		return -1;
	}
	return stack->arr[stack->top];
}

void deleteStack(struct Stack* stack)
{
	stack->arr = NULL;
}

int main()
{
	struct Stack* stack = createStack(5);
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
	
	printf("%d\n", pop(stack));
	printf("%d\n", peek(stack));
	printf("%d\n", pop(stack));
	printf("%d\n", pop(stack));
	
	return 0;
}
