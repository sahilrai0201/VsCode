//CIRCULAR QUEUE IMPLEMENTATION USING ARRAY : 

#include <bits/stdc++.h>
using namespace std;

class Queue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Constructor
    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if queue is full
    bool isFull() {
        return ((rear + 1) % size == front);
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }

        // First element insertion
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        cout << value << " enqueued\n";
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        int removed = arr[front];

        // If only one element left
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }

        cout << removed << " dequeued\n";
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    q.dequeue();
    q.dequeue();

    q.enqueue(50);
    q.enqueue(60);

    q.display();

    return 0;
}