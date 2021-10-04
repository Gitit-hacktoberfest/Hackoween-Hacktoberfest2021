//stack linked list implementation
#include <bits/stdc++.h>
using namespace std;

struct stackNode
{
    int data;
    stackNode *next;
};

stackNode * top = NULL;

void push(int x)
{
    stackNode *new_node = new stackNode;
    new_node->data = x;
    new_node->next = top;
    top = new_node;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Underflow" << endl;
    }
    stackNode *temp = top;
    top = (top)->next;
    free(temp);
}

int peep()
{
    if (top != NULL)
    {
        return (top)->data;
    }
    return -1;
}

bool isEmpty()
{
    return top == NULL ? true : false;
}

int main()
{
    stackNode *root = NULL;
    push(2);
    push(3);
    push(1);
    push(4);
    cout<<peep()<<endl;
    pop();
    pop();
    pop();
    pop();
    pop();

    cout<<peep()<<endl;
    
}