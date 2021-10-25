#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Ctype.h>

char postfix[100];
int stack[100]={0}, top=-1;

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

void convert()
{
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
	convert();
	printf("%d",stack[0]);
  // Time complexity is O(n), where n is the length of the postfix string
  // Space complexity is O(n), where n is the length of the postfix string
}
