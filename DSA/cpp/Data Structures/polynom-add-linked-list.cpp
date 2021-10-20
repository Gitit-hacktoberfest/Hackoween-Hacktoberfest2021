/*
Program to represent a polynomial expression using linked list and implement functions to perform Polynomial addition operation 
*/

#include <bits/stdc++.h>
using namespace std;

struct polyNode {
    int coeff;
    int pow;
    struct polyNode *next;
};

struct polyNode* head=NULL;
void getexp(int num1,int num2)
{
    struct polyNode* temp = new polyNode();
    temp->coeff = num1;
    temp->pow = num2;
    temp->next = head;
    head=temp;
}
void add(int size){
    int num1,num2;
    struct polyNode* temp1=head;
    struct polyNode* temp2=head->next;
    int i;
    cout<<"Addition :";
    while (temp1 != NULL) {
            temp2=temp1->next;
        while(temp2 != NULL) {
            if((temp1->pow==temp2->pow) && size>0){
                num1=(temp1->coeff)+(temp2->coeff);
                num2=temp2->pow;
                i=num2;
                cout<<num1<<"x^"<<num2<<" + ";
                i=0;
                size--;
            }
            i=90;
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    cout << endl;
}
int main()
{
    int num1,num2,i=0,size1,size2;
    cout<<"enter total number of terms in exp 1\n";
    cin>>size1;
    cout<<"Enter coefficient and power for equation 1 \n";
    while(i<size1){
        cin>>num1;
        cin>>num2;
        getexp(num1,num2);
        i++;
    }
    cout<<"enter total number of terms in exp 2\n";
    cin>>size2;
    i=0;
    cout<<"Enter coefficient and power for equation 2 \n";
    while(i<size2){
        cin>>num1;
        cin>>num2;
        getexp(num1,num2);
        i++;
    }
    add(size1+size2);
    return 0;
}
