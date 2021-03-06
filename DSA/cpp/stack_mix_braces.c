#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stack
{
    int top;
    int size;
    char *arr;
} stack;
int pop(stack *,char);
int push(stack *,char);
int isEmpty(stack *);
int isFull(stack *);
int main()
{
    stack s;
    char a[200];
    int i;
    s.top = 0;
    s.size = 100;
    s.arr = (char *)malloc(100 * sizeof(char));
    gets(a);

    for(i=0;a[i]!='\0';i++)
    {   
        if(a[i]=='(' || a[i]=='{' || a[i]=='[')
        {
            if(push(&s,a[i]))   continue;
            else break;
        }
        else if(a[i]==')' || a[i]=='}' || a[i]==']')
        {   
            if(pop(&s,a[i])) continue;
            else break;
        }
        else continue;
    }

    if(a[i]=='\0' && s.top==0) printf("correct combination\n");
    else printf("wrong one!\n");
    return 0;
}
int pop(stack * a,char c)
{   char test;
            if(c==')')test='(';
            else if(c=='}')test='{';
            else if(c==']')test='[';
    if(isEmpty(a) || a->arr[a->top-1]!=test) return 0;
    else {a->top--;     return 1;}
}
int push(stack *a,char c)
{   
    if(isFull(a)) return 0;
    else {a->arr[a->top++]=c;     return 1;}
}
int isEmpty(stack *a)
{
    if(a->top==0) return 1;
    else return 0;
}
int isFull(stack *a)
{
  if(a->top==a->size) return 1;
  else return 0;  
}