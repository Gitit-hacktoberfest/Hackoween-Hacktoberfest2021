//circular queue array implementation
#include<iostream>
using namespace std;

#define n 10

class queue{
    int front,rear;
    int arr[n];

    public:
        queue(){
            front=rear=-1;
        }

        void enqueue(int data){
            if( rear==front-1 || (front==0 && rear==n-1) ){
                cout<<"Overflow condition";
                return;
            }

            if(front==-1){
                front=rear=0;
            }
            else{
                rear=(rear+1)%n;
            }
            arr[rear]=data;
        }

        void dequeue(){
            if( front==-1 ){
                cout<<"underflow condition";
                return;
            }

            int data = arr[front];
            if( front==rear ){
                front=rear=-1;
            }
            else{
                front=(front+1)%n;
            }
            cout<<"Successfully deleted "<<data;
        }

        int peek(){
            if(front!=-1){
                return arr[front];
            }
            return -1;
        }

        bool empty(){
            if( front==-1 )
                return true;

            return false; 
        }

        int getFront(){
            return front;
        }
        int getRear(){
            return rear;
        }
};

int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    cout<<q.peek();
    q.dequeue();
    cout<<q.peek();
    
    q.enqueue(10);
    q.enqueue(11);
    cout<<q.getFront()<<" "<<q.getRear();
    cout<<q.peek();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
cout<<q.getFront()<<" "<<q.getRear();
    cout<<q.peek();
    q.dequeue();
    cout<<q.getFront()<<" "<<q.getRear();
    cout<<q.peek();
    q.dequeue();
    cout<<q.getFront()<<" "<<q.getRear();
    cout<<q.peek();
    q.enqueue(12);
    cout<<q.getFront()<<" "<<q.getRear();
    cout<<q.peek();
    return 0;
}