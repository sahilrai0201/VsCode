#include<iostream>
using namespace std;

class kQueue{
public:
    int n;          // total size of array
    int k;          // number of queues
    int *front;     // array of front pointers
    int *rear;      // array of rear pointers
    int *arr;       // main array to store elements
    int freeSpot;   // beginning index of free list
    int *next;      // next array

public:
    // constructor
    kQueue(int n, int k){
        this->n = n;
        this->k = k;

        front = new int[k];
        rear = new int[k];

        for(int i = 0; i < k; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for(int i = 0; i < n-1; i++){
            next[i] = i + 1;
        }
        next[n-1] = -1;

        arr = new int[n];
        freeSpot = 0;
    }

    // ENQUEUE
    void enqueue(int data, int qn){

        if(qn < 1 || qn > k){
            cout << "Invalid Queue Number!" << endl;
            return;
        }

        // Overflow
        if(freeSpot == -1){
            cout << "No empty space available!" << endl;
            return;
        }

        // get first free index
        int index = freeSpot;

        // update freeSpot
        freeSpot = next[index];

        // first element in queue
        if(front[qn-1] == -1){
            front[qn-1] = index;
        }
        else{
            next[rear[qn-1]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[qn-1] = index;

        // insert element
        arr[index] = data;
    }

    // DEQUEUE
    int dequeue(int qn){

        if(qn < 1 || qn > k){
            cout << "Invalid Queue Number!" << endl;
            return -1;
        }

        // Underflow
        if(front[qn-1] == -1){
            cout << "Queue Underflow!" << endl;
            return -1;
        }

        // get index to remove
        int index = front[qn-1];

        // move front
        front[qn-1] = next[index];

        // if queue becomes empty
        if(front[qn-1] == -1){
            rear[qn-1] = -1;
        }

        // add this index to free list
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    // Destructor
    ~kQueue(){
        delete[] front;
        delete[] rear;
        delete[] arr;
        delete[] next;
    }
};

int main(){

    kQueue q(10, 3);

    q.enqueue(10, 1);
    q.enqueue(20, 1);
    q.enqueue(30, 2);

    cout << "Dequeued from Queue 1: " << q.dequeue(1) << endl;
    cout << "Dequeued from Queue 2: " << q.dequeue(2) << endl;

    return 0;
}