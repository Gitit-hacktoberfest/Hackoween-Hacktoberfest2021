#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

struct CircularDoubleLinkedList
{
	struct node* head;
	struct node* tail;
};

struct CircularDoubleLinkedList* createLinkedList(int value) 
{
	struct CircularDoubleLinkedList* list = (struct CircularDoubleLinkedList*)malloc(sizeof(struct CircularDoubleLinkedList));
	list->head = (struct node*)malloc(sizeof(struct node));
	list->tail = (struct node*)malloc(sizeof(struct node));
	struct node* first = (struct node*)malloc(sizeof(struct node));
	first->data = value;
	list->head = first;
	list->tail = first;
	first->next = first;
	first->prev = first;
	
	return list;
}

int isExist(struct CircularDoubleLinkedList* list)
{
	if(list->head == NULL && list->tail == NULL) {
		return 0;
	}
	return 1;
}

int length(struct CircularDoubleLinkedList* list)
{
	int len = 0;
	struct node* temp = list->head;
	while(temp != list->tail) {
		len += 1;
		temp = temp->next;
	}
	return (len+1);
}

void insertion(struct CircularDoubleLinkedList* list, int value, int location)
{
	struct node* current = (struct node*)malloc(sizeof(struct node));
	current->data = value;
	if(!isExist(list)) {
		printf("The linked list does not exist.");
	}
	else {
		if(location == 0) {
			current->next = list->head;
			current->prev = list->tail;
			list->head->prev = current;
			list->tail->next = current;
			list->head = current;
		}
		else if(location == length(list) || location == length(list) - 1) {
			current->next = list->head;
			current->prev = list->tail;
			list->head->prev = current;
			list->tail->next = current;
			list->tail = current;
		}
		else {
			struct node* temp = list->head;
			int i = 0;
			while(i < location - 1) {
				temp = temp->next;
				i++;
			}
			current->next = temp->next;
			current->prev = temp;
			temp->next = current;
			current->next->prev = current;
		}
	}
}

void deletion(struct CircularDoubleLinkedList* list, int location)
{
	if(!isExist(list)) {
		printf("The Linked list does not exist.");
	}
	else {
		if(location == 0) {
			if(length(list) == 0) {
				list->head->next = NULL;
				list->head->prev = NULL;
				list->head = NULL;
				list->tail = NULL;
			}
			else {
				list->head = list->head->next;
				list->head->prev = list->tail;
				list->tail->next = list->head;
			}
		}
		else if(location == length(list) || location == length(list) - 1 ) {
			if(length(list) == 0) {
				list->head->next = NULL;
				list->head->prev = NULL;
				list->head = NULL;
				list->tail = NULL;
			}
			else {
				list->tail = list->tail->prev;
				list->tail->next = list->head;
				list->head->prev = list->tail;
			}
		}
		else {
			struct node* temp = list->head;
			int i = 0;
			while(i < location - 1 ) {
				temp = temp->next;
				i++;
			}
			temp->next = temp->next->next;
			temp->next->prev = temp;
		}
	}
}

void deleteLinkedList(struct CircularDoubleLinkedList* list)
{
	list->tail->next = NULL;
	struct node* temp = list->head;
	while(temp != list->tail) {
		temp->prev = NULL;
	}
	list->head = NULL;
	list->tail = NULL;
}

void displayFront(struct CircularDoubleLinkedList* list)
{
	struct node* temp = list->head;
	while(temp != list->tail) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d ", temp->data);
	printf("\n");
}

void displayBack(struct CircularDoubleLinkedList* list)
{
	struct node* temp = list->tail;
	while(temp != list->head) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("%d\n", temp->data);
}

int main()
{
	struct CircularDoubleLinkedList* list = createLinkedList(1);
	insertion(list, 2, 1);
	insertion(list, 3, 2);
	insertion(list, 4, 3);
	insertion(list, 5, 4);
	displayFront(list);
	
	deletion(list, 0);
	displayFront(list);
	deletion(list, 4);
	displayFront(list);
	deletion(list, 1);
	displayFront(list);
	
	
	return 0;
}
