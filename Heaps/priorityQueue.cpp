#include<bits/stdc++.h>
using namespace std;

int main(){

    cout << "Priority queue -> " << endl;

    //default max heap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout << "Element at the top is : " << pq.top() << endl;
    pq.pop();
    cout << "Element at the top is : " << pq.top() << endl;
    cout << "Size : " << pq.size() << endl;
    if(pq.empty()){
        cout << "pq is empty" << endl;
    }
    else{
        cout << "pq is not empty" << endl;
    }


    //min heap
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);
    cout << "Element at the top is : " << minheap.top() << endl;
    minheap.pop();
    cout << "Element at the top is : " << minheap.top() << endl;
    cout << "Size : " << minheap.size() << endl;
    if(minheap.empty()){
        cout << "pq is empty" << endl;
    }
    else{
        cout << "pq is not empty" << endl;
    }

    
    return 0;
}