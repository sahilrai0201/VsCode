// DEQUE EXPLANATION

#include<bits/stdc++.h>
using namespace std;

void explainDeque(){

    // deque = Double Ended Queue
    // Allows insertion and deletion from both ends
    deque<int> dq;

    // Insert at back
    dq.push_back(1);        // {1}
    dq.emplace_back(2);     // {1,2}

    // Insert at front
    dq.push_front(3);       // {3,1,2}
    dq.emplace_front(4);    // {4,3,1,2}

    // Print elements
    cout << "Deque elements: ";
    for(auto it : dq){
        cout << it << " ";
    }
    cout << endl;

    // Remove from back
    dq.pop_back();          // removes 2 → {4,3,1}

    // Remove from front
    dq.pop_front();         // removes 4 → {3,1}

    cout << "After popping: ";
    for(auto it : dq){
        cout << it << " ";
    }
    cout << endl;

    // Access front and back
    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;

    // Random access is allowed (like vector)
    cout << "Element at index 0 : " << dq[0] << endl;
}

int main(){
    explainDeque();
    return 0;
}