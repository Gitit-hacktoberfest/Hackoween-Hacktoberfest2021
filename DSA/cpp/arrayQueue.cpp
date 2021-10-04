//Queue array implementation
#include<bits/stdc++.h>
using namespace std;
#define max 10
class Queue{
    int front,rear;
    int arr[max];
    
    public:
        Queue(){
            front=-1;
            rear=-1;
        }
        void enqueue(int data){
            if(rear==max-1){
                cout<<"Overflow Condition\n";
            }
            else{
                if(front==-1 && rear==-1){
                    front=0;
                    rear=0;
                }
                else{
                    rear+=1;
                }
                arr[rear]=data;
            }
        }
        void dequeue(){
            if(front==-1){
                cout<<"Underflow Condition";
            }
            else{
                cout<<arr[front]<<" is deleted fron index "<<front<<endl;
                if((front==0 && rear==0) || (front==max-1 && rear==max-1)){
                    front = -1;
                    rear=-1;
                }
                else{
                    front++;
                }                
            }
        }
        void display(){
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    Queue q;
    q.enqueue(7);
    q.enqueue(1);
    q.enqueue(9);
    q.enqueue(8);
    q.enqueue(4);
    q.enqueue(4);
    q.enqueue(4);
    q.enqueue(4);
    q.enqueue(4);
    q.enqueue(4);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(4);
    q.enqueue(4);
    q.enqueue(4);

    
    q.display();
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a queue 
class Queue 
{ 
    public:
    int front, rear, size; 
    unsigned capacity; 
    int* array; 
}; 

// function to create a queue of a given capacity. 
// It initializes the size of the queue as 0 
Queue* createQueue(unsigned capacity) 
{ 
    Queue* queue = new Queue();
    queue->capacity = capacity; 
    queue->front = queue->size = 0; 
    queue->rear = capacity - 1; // This is important, see the enqueue 
    queue->array = new int[(queue->capacity * sizeof(int))]; 
    return queue; 
} 

// Queue is full when size 
// becomes equal to the capacity 
int isFull(Queue* queue) 
{ return (queue->size == queue->capacity); } 

// Queue is empty when size is 0 
int isEmpty(Queue* queue) 
{ return (queue->size == 0); } 

// Function to add an item to the queue. 
// It changes rear and size 
void enqueue(Queue* queue, int item) 
{ 
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1) % queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    cout << item << " enqueued to queue\n"; 
} 

// Function to remove an item from the queue. 
// It changes front and size 
int dequeue(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1) % queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 

// Function to get front of queue 
int front(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->front]; 
} 

// Function to get rear of queue 
int rear(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->rear]; 
} 

// Driver code
int main() 
{ 
    Queue* queue = createQueue(1000); 

    enqueue(queue, 10); 
    enqueue(queue, 20); 
    enqueue(queue, 30); 
    enqueue(queue, 40); 

    cout<<dequeue(queue)<<" dequeued from queue\n"; 

    cout << "Front item is " << front(queue) << endl; 
    cout << "Rear item is " << rear(queue) << endl; 

    return 0; 
}*/