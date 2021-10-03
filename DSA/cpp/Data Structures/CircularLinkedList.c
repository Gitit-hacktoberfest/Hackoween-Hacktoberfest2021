#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct CircularLinkedList
{
	struct node* head;
	struct node* tail;
};

struct CircularLinkedList* createCircularLinkedList(int value)
{
	struct CircularLinkedList* list = (struct LinkedList*)malloc(sizeof(struct CircularLinkedList));
	list->head = (struct node*)malloc(sizeof(struct node));
	list->tail = (struct node*)malloc(sizeof(struct node));
	struct node* first = (struct node*)malloc(sizeof(struct node));
	first->data = value;
	first->next = first;
	list->head = first;
	list->tail = first;
	
	return list;
}

int isExist(struct CircularLinkedList* list)
{
	if(list->head == NULL && list->tail == NULL) {
		return 0;
	}
	return 1;
}

int length(struct CircularLinkedList* list)
{
	int len = 0;
	struct node* temp = list->head;
	while(temp != list->tail) {
		len += 1;
		temp = temp->next;
	}
	return (len+1);
}

void insertLinkedList(struct CircularLinkedList* list, int value, int location)
{
	struct node* current = (struct node*)malloc(sizeof(struct node));
	current->data = value;
	if(!isExist(list)) {
		printf("The linked list does not exist.");
	}
	else {
		if(location == 0) {
			current->next = list->head;
			list->head = current;
			list->tail->next = list->head;
		}
		else if(location == length(list)) {
			current->next = list->head;
			list->tail->next = current;
			list->tail = current;
		}
		else {
			int i = 0;
			struct node* temp = list->head;
			while(i < location - 1) {
				temp = temp->next;
				i++;
			}
			current->next = temp->next;
			temp->next = current;
		}
	}
}

void deletion(struct CircularLinkedList* list, int location)
{
	if(!isExist(list)) {
		printf("The linked list does not exist.");
	}
	else {
		if(location == 0) {
			list->head = list->head->next;
			list->tail->next = list->head;
			if(length(list) == 1) {
				list->head = NULL;
				list->tail = NULL;
			}
		}
		else if(location == length(list) || location == length(list) - 1) {
			if(length(list) == 1) {
				list->head = NULL;
				list->tail = NULL;
			}
			else {
				int i = 0;
				struct node* temp = list->head;
				while(i < location - 1) {
					temp = temp->next;
					i++;
				}
				list->tail = temp;
				temp->next = list->head;
			}
		}
		else {
			int i = 0;
			struct node* temp = list->head;
			while(i < location - 1) {
				temp = temp->next;
				i++;
			}
			temp->next = temp->next->next;
		}
	}
}

void deleteLinkedList(struct CircularLinkedList* list)
{
	list->head = NULL;
	list->tail->next = NULL;
	list->tail = NULL;
}

void display(struct CircularLinkedList* list)
{
	struct node* temp = list->head;
	while(temp != list->tail) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d ", temp->data);
	printf("\n");
}

int main()
{
	struct CircularLinkedList* list = createCircularLinkedList(1);
	insertLinkedList(list, 2, 1);
	insertLinkedList(list, 3, 2);
	insertLinkedList(list, 4, 3);
	display(list);
	
	deletion(list, 0);
	display(list);
	deletion(list, 1);
	display(list);
	deletion(list, 1);
	display(list);
	
	return 0;
}
