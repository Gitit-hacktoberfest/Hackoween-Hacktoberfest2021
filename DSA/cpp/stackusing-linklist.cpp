#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    struct node*next;
}*Top=NULL,*curr,*newn;

void push();
void pop();
void peep();
void display();

int main(){
    int option,i;
    i=0;
    while(i==0){
        cout<<"Press 1.Push 2.Pop 3.Peep 4.Display 5.Exit\n";
        cin>>option;
        switch(option){
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:peep();
            break;
            case 4:display();
            break;
            case 5: i=1;
            break;
        }
    }

    return 0;
}
void push(){
     newn=(struct node*)malloc(sizeof(struct node));
     int val;
     cout<<"Enter the value to be pushed\n";
     cin>>newn->data;
     newn->next=NULL;
     if(Top==NULL){
         Top=newn;
         curr=newn;
     }
     else{
         newn->next=Top;
         Top=newn;
     }
     cout<<"Pushed successful\n";
}
void pop(){
      if(Top!=NULL){
         newn=Top->next;
         Top=newn;
         cout<<"Poped successful\n";
      }
      else{
          cout<<"Nothing to pop\n";
      }
         
}
void peep(){
    if(Top==NULL){
        cout<<"Stack is empty\n";
    }
    else{
        cout<<"The top value of stack is "<<Top->data<<"\n";
    }
}
void display(){
    struct node *t;
    t=Top;
    while(t!=NULL){
        cout<<t->data<<"->";
        t=t->next;
   }
   if(t==NULL){
      cout<<" Nothing to show\n";
   }
}