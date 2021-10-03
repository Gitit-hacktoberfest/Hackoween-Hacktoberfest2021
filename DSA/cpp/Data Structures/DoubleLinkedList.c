#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

struct DoubleLinkedList
{
	struct node* head;
	struct node* tail;
};

struct DoubleLinkedList* createList(int value)
{
	struct DoubleLinkedList* list = (struct DoubleLinkedList*)malloc(sizeof(struct DoubleLinkedList));
	list->head = (struct node*)malloc(sizeof(struct node));
	list->tail = (struct node*)malloc(sizeof(struct node));
	struct node* first = (struct node*)malloc(sizeof(struct node));
	first->data = value;
	first->next = NULL;
	first->prev = NULL;
	list->head = first;
	list->tail = first;
	
	return list;
}

int isExist(struct DoubleLinkedList* list)
{
	if(list->head == NULL && list->tail == NULL) {
		return 0;
	}
	return 1;
}

int length(struct DoubleLinkedList* list)
{
	int len = 0;
	struct node* temp = list->head;
	while(temp->next != NULL) {
		len += 1;
		temp = temp->next;
	}
	
	return (len+1);
}

void insertLinkedList(struct DoubleLinkedList* list, int value, int location)
{
	struct node* current = (struct node*)malloc(sizeof(struct node));
	current->data = value;
	if(!isExist(list)) {
		printf("Double linked list does not exist.");
	}
	else {
		if(location == 0) {
			current->next = list->head;
			current->prev = NULL;
			list->head->prev = current;
			list->head = current;
		}
		else if(location == length(list)) {
			current->next = NULL;
			current->prev = list->tail;
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

void deletion(struct DoubleLinkedList* list, int location)
{
	if(!isExist(list)) {
		printf("The Double linked list does not exist.");
	}
	else {
		if(location == 0) {
			if(length(list) == 1) {
				list->head = NULL;
				list->tail = NULL;
			}
			else {
				list->head = list->head->next;
				list->head->prev = NULL;
			}
		}
		else if(location == length(list)) {
			list->tail = list->tail->prev;
			list->tail->next = NULL;
		}
		else {
			int i = 0;
			struct node* temp = list->head;
			while(i < location - 1) {
				temp = temp->next;
				i++;
			}
			temp->next = temp->next->next;
			temp->next->prev = temp;
		}
	}
}

void displayFront(struct DoubleLinkedList* list)
{
	struct node* temp = list->head;
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void displayBack(struct DoubleLinkedList* list)
{
	struct node* temp = list->tail;
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main()
{
	struct DoubleLinkedList* list = createList(1);
	insertLinkedList(list, 2, 1);
	insertLinkedList(list, 3, 2);
	insertLinkedList(list, 4, 3);
	
	displayFront(list);
	deletion(list, 2);
	displayFront(list);
	
	return 0;
}
