// QUEUE EXPLANATION

#include<bits/stdc++.h>
using namespace std;

void explainQueue(){

    // Queue declaration (FIFO)
    queue<int> q;

    // Insert elements at the back
    q.push(10);      // {10}
    q.push(20);      // {10,20}
    q.emplace(30);   // {10,20,30}

    // Access front element
    cout << "Front element: " << q.front() << endl;  // 10

    // Access last element
    cout << "Back element: " << q.back() << endl;    // 30

    // Remove front element
    q.pop();   // removes 10

    cout << "After pop, front: " << q.front() << endl;  // 20

    // Size of queue
    cout << "Size: " << q.size() << endl;

    // Check if empty
    cout << "Is empty? " << q.empty() << endl;

    // Printing queue (must use copy)
    queue<int> temp = q;

    cout << "Queue elements: ";
    while(!temp.empty()){
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Swap example
    queue<int> q1, q2;
    q1.push(100);
    q2.push(200);

    q1.swap(q2);

    cout << "Front of q1 after swap: " << q1.front() << endl;  // 200
}

int main(){
    explainQueue();
    return 0;
}