#include <stdio.h>
#include <stdlib.h>


//C code for implementing stack using linked list and some of its basic functionality


struct stack{
    int data;
    struct stack* next;
};

//function to show the top element of the stack
void show(struct stack* tp){
    while(tp!=NULL){
        printf("%d\n",tp->data);
        tp = tp->next;
    }
}

//function to push new element into the stack
struct stack* push(int n,struct stack* top){
    struct stack* node = (struct stack*)malloc(sizeof(struct stack));
    node->data = n;
    node ->next = top;
    top = node;
    printf("%d is pushed\n",n);
    return top;
}

//function to remove the topmost element in the stack

struct stack* pop(struct stack* a){
    struct stack* ptr = a;
    printf("%d is popped\n",ptr->data);
    a = a->next;
    free(ptr);
    return a;
}

//driver code

int main(){
    struct stack* top = NULL;
    top = push(4,top);
    top = push(7,top);
    top = pop(top);
    top = pop(top);
}