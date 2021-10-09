#include<stdio.h>
#include<stdlib.h>
struct doubleLL{
    int data;
    struct doubleLL *llink;
    struct doubleLL *rlink;
}*newnode,*head=NULL,*tail=NULL,*term;

void insert_end(int ele){
    newnode=(struct doubleLL*)malloc(sizeof(struct doubleLL));
    newnode->data=ele;
    newnode->rlink=head;
    if(head==NULL){
        head=tail=newnode;
        head->rlink=newnode;
        head->llink=newnode;
    }
    else{
        tail->rlink=newnode;
        newnode->llink=tail;
        tail=newnode;
        head->llink=tail;
    }
}
void disp(){
    if (head==NULL){
        printf("Empty");
    }
    term=head;
    do{
    printf("%d ",term->data);
    term=term->rlink;
    }while(term!=head);
    printf("\n");
}
void rem(int pos){
    while(pos!=1){
        newnode=newnode->rlink;
        pos--;
    }
    printf("Element to be removed now is:%d and ",newnode->data);
    if(head==newnode){
    newnode->llink->rlink=newnode->rlink;
    newnode->rlink->llink=newnode->llink;
    newnode=newnode->rlink;
    head=newnode;
    
    }
    else{
    newnode->llink->rlink=newnode->rlink;
    newnode->rlink->llink=newnode->llink;
    newnode=newnode->rlink;
    }
    printf("%d has the knife\n",newnode->data);
}
int count(){
    int c=0;
    term=head;
    do{
    c++;
    term=term->rlink;
    }while(term!=head);
    return c;
}
int main(){
    int num;
    int point;
    printf("Enter the number of participant :- ");
    scanf("%d",&num);
    printf("\nAfter what value it should kill :- ");
    scanf("%d",&point);
    for(int i=0;i<num;i++)
    {
        insert_end(i+1);
    }

    printf("%d has the knife\n",head->data);
    disp();
    int c=0;
    newnode=head;
    while(c!=1){
        rem(point);
        disp();
        c=count();
    }
    printf("%d is the Winner!\n",head->data);
    return 1;
}