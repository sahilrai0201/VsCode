// QUEUE OPERATIONS/IMPLEMENTATION USING ARRAY BY DEFINING CLASS QUEUE : 

#include<bits/stdc++.h>
using namespace std;

class Queue {
    // properties
    int *arr;
    int front;
    int rear;
    int size;

public:
    // constructor
    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = -1;
    }

    // enqueue (push)
    void enqueue(int element){
        if(rear < size - 1){
            rear++;
            arr[rear] = element;
        } else {
            cout << "Queue Overflow" << endl;
        }
    }

    // dequeue (pop)
    void dequeue(){
        if(front <= rear){
            front++;
        } else {
            cout << "Queue Underflow" << endl;
        }
    }

    // front element
    int peek(){
        if(front <= rear){
            return arr[front];
        } else {
            cout << "Queue is Empty" << endl;
            return -1;
        }
    }

    // is empty
    bool isEmpty(){
        return front > rear;
    }

    // size of queue
    int getSize(){
        if(front > rear){
            return 0;
        }
        return rear - front + 1;
    }

};

int main(){

    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // Queue Overflow

    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    cout << "Front element is: " << q.peek() << endl;

    cout << "size of queue is : " << q.getSize() << endl;

    if(q.isEmpty()){
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}