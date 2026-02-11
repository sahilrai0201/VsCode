// QUEUE OPERATIONS/IMPLEMENTATION USING LINKED LIST : 

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
    // properties
    Node* front;
    Node* rear;
    int size;

public:
    // constructor
    Queue(){
        front = NULL;
        rear = NULL;
        size = 0;
    }

    // enqueue
    void enqueue(int element){
        Node* newNode = new Node(element);

        if(rear == NULL){
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // dequeue
    void dequeue(){
        if(front == NULL){
            cout << "Queue Underflow" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
        size--;

        if(front == NULL){
            rear = NULL;
        }
    }

    // front element
    int peek(){
        if(front == NULL){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return front->data;
    }

    // is empty
    bool isEmpty(){
        return front == NULL;
    }

    // size of queue
    int getSize(){
        return size;
    }
};

int main(){

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    cout << "Front element is: " << q.peek() << endl;

    cout << "Size of queue is: " << q.getSize() << endl;

    if(q.isEmpty()){
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}