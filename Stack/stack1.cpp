//STACK OPERATIONS/IMPLEMENTATION USING CPP STL: 

#include<bits/stdc++.h>
using namespace std;

int main(){

    //creation of stack
    stack<int> s;

    //push operation
    s.push(10);
    s.push(20);
    s.push(30);

    //pop operation
    s.pop();

    //checking top element
    cout << "Top element is: " << s.top() << endl;

    //checking if stack is empty
    if(s.empty()){
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    //size of stack
    cout << "Size of stack is: " << s.size() << endl;
    

    return 0;
}