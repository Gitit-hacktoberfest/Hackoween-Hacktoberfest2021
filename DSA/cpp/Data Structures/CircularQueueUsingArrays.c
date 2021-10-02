#include<stdio.h>
#include<stdlib.h>

struct CircularQueue
{
	int top;
	int beg;
	int size;
	int* arr;
};

struct CircularQueue* createQueue(int capacity)
{
	struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
	queue->beg = -1;
	queue->top = -1;
	queue->size = capacity;
	queue->arr = (int *)malloc(sizeof(capacity * sizeof(int)));
	
	return queue;
}

int isFull(struct CircularQueue* queue)
{
	
	if(queue->beg == queue->top + 1) {
		return 1;
	}
	if( (queue->top == queue->size - 1) && (queue->beg == 0) ) {
		return 1;
	}
	return 0;
}

int isEmpty(struct CircularQueue* queue)
{
	if(queue->top == -1) {
		return 1;
	}
	return 0;
}

void enQueue(struct CircularQueue* queue, int data)
{
	if(isFull(queue)) {
		printf("The queue is full.\n");
	}
	else {
		if( queue->top + 1 == queue->size ) {
			queue->top = -1;
		}
	
		queue->arr[++queue->top] = data;
	}
}

int deQueue(struct CircularQueue* queue)
{
	if(isEmpty(queue)) {
		printf("The queue is empty.");
	}
	else {
		if(queue->beg == queue->top) {
			queue->top = -1;
			queue->beg = -1;
		}
		else if(queue->beg + 1 == queue->size) {
			queue->beg = -1;
		}
		int data = queue->arr[++queue->beg];
		return data;
	}
}

int peek(struct CircularQueue* queue)
{
	if(isEmpty(queue)) {
		printf("The queue is empty.");
	}
	else {
		return queue->arr[queue->beg];
	}
}

void deleteQueue(struct CircularQueue* queue)
{
	queue->arr = NULL;
}

int main()
{
	struct CircularQueue* queue = createQueue(4);
	enQueue(queue, 1);
	enQueue(queue, 2);
	enQueue(queue, 3);
	printf("%d\n", deQueue(queue));
	printf("%d\n", deQueue(queue));
	enQueue(queue, 10);
	enQueue(queue, 20);
	printf("%d\n", deQueue(queue));
	printf("%d\n", deQueue(queue));
	printf("%d\n", deQueue(queue));
	
	return 0;
}
