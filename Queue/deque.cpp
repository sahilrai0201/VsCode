//DEQUE IMPLEMENTATION USING STL FUNCTIONS : 

#include<bits/stdc++.h>
using namespace std;

int main(){
    //creation
    deque<int> d;

    //push operations
    d.push_front(12);      //front end
    d.push_back(14);      //rear end

    cout << d.front() << endl;     //12
    cout << d.back() << endl;     //14

    //pop operations
    d.pop_front();

    cout << d.front() << endl;     //14
    cout << d.back() << endl;        //14

    d.pop_back();

    if(d.empty()){
        cout << "queue is empty!" << endl;
    }
    else{
        cout << "queue is not empty!" << endl;
    }

    return 0;
}
