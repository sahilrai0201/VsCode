//QUEUE IMPLEMENTATION USING CPP STL FUNCTIONS : 

#include<bits/stdc++.h>
// #include<iostream>
// #include<queue>
using namespace std;

int main(){
    //queue follows FIFO order

    //creation of queue
    queue<int> q;

    //push operation - done from rear end in queue
    q.push(11);

    //checking front element
    cout << "front of queue is : " << q.front() << endl;

    q.push(15);
    q.push(13);

    //size 
    cout << "size of queue is : " << q.size() << endl;

    //pop operation - done from front end in queue
    q.pop();

    //size 
    cout << "size of queue is : " << q.size() << endl;

    //checking if q is empty
    if(q.empty()){
        cout << "Queue is empty!" << endl;
    }
    else{
        cout << "Queue is not empty!" << endl;
    }

    return 0;
}



