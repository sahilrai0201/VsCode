// PRIORITY QUEUE (MAX HEAP)
#include<bits/stdc++.h>
using namespace std;

void explainPriorityQueue(){
    priority_queue<int> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);

    // Largest element at top
    cout << "Top element: " << pq.top() << endl;  // 30

    pq.pop();   // removes 30
    cout << "After pop, top: " << pq.top() << endl;  // 20

    cout << "Size: " << pq.size() << endl;

    cout << "Elements: ";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main(){
    explainPriorityQueue();
    return 0;
}





// PRIORITY QUEUE USING MIN HEAP : 
// #include<bits/stdc++.h>
// using namespace std;

// void explainMinHeap(){

//     // Min Heap
//     priority_queue<int, vector<int>, greater<int>> pq;

//     pq.push(10);
//     pq.push(30);
//     pq.push(20);
//     pq.push(5);

//     // Smallest element will be at top
//     cout << "Top element (smallest): " << pq.top() << endl;

//     cout << "Elements in increasing order: ";
//     while(!pq.empty()){
//         cout << pq.top() << " ";
//         pq.pop();
//     }
// }

// int main(){
//     explainMinHeap();
//     return 0;
// }