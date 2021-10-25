#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Ctype.h>

char postfix[100];
int stack[100]={0}, top=-1; // array implementation of stack

void push(int d)
{
	stack[++top]=d;
}

int pop()
{
	if(top==-1)
		return -1;
	else
		return stack[top--];
}

void evaluate()
{
	// 4 operators are present in the postfix expression
	for(int i=0;i<strlen(postfix);i++)
	{
		char c=postfix[i];
		if(isdigit(c))
			push(postfix[i]-'0');
		else if(c=='+')
			push(pop()+pop());
		else if(c=='-')
			push(pop()-pop());
		else if(c=='*')
			push(pop()*pop());
		else if(c=='/')
			push(pop()/pop());
	}
}

int main()
{
	scanf("%s",postfix);
	evaluate();
	printf("%d",stack[0]); // The final answer will be stored on the stack
  // Time complexity is O(n), where n is the length of the postfix string
  // Space complexity is O(n), where n is the length of the postfix string
}
