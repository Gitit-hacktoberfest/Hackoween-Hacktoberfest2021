#include<stdio.h>
#include<stdlib.h>

struct Queue
{
	int top;
	int beg;
	int size;
	int* arr;
};

struct Queue* createQueue(int capacity)
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->top = -1;
	queue->beg = -1;
	queue->size = capacity;
	queue->arr = (int *)malloc(sizeof(capacity * sizeof(int)));
	
	return queue;
}

int isFull(struct Queue* queue)
{
	if(queue->top == queue->size - 1) {
		return 1;
	}
	return 0;
}

int isEmpty(struct Queue* queue)
{
	if(queue->top == -1) {
		return 1;
	}
	return 0;
}

void enQueue(struct Queue* queue, int data)
{
	if(isFull(queue)) {
		printf("Queue is full.");
	}
	else{
		queue->arr[++queue->top] = data;
	}
}

int deQueue(struct Queue* queue)
{
	if(isEmpty(queue)) {
		printf("The queue is empty.");
	}
	else {
		int ele = queue->arr[++queue->beg];
		if(queue->beg > queue->top) {
			queue->top = -1;
			queue->beg = -1;
		}
		return ele;
	}
}

int peek(struct Queue* queue)
{
	if(isEmpty(queue)) {
		printf("The queue is empty.");
	}
	else {
		return queue->arr[queue->beg];
	}
}

int main()
{
	struct Queue* queue = createQueue(5);
	enQueue(queue, 1);
	enQueue(queue, 2);
	enQueue(queue, 3);
	enQueue(queue, 4);
	
	printf("%d\n", deQueue(queue));
	printf("%d\n", deQueue(queue));
	printf("%d\n", deQueue(queue));
	printf("%d\n", deQueue(queue));
	
	return 0;
}
