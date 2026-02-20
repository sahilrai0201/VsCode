// STACK EXPLANATION

#include<bits/stdc++.h>
using namespace std;

void explainStack(){

    // Stack declaration (LIFO structure)
    stack<int> st;

    // Insert elements
    st.push(10);      // bottom
    st.push(20);
    st.emplace(30);   // top

    // Access top element
    cout << "Top element: " << st.top() << endl;  // 30

    // Remove top element
    st.pop();         // removes 30

    cout << "After pop, top: " << st.top() << endl;  // 20

    // Stack size
    cout << "Size: " << st.size() << endl;

    // Check if stack is empty
    cout << "Is empty? " << st.empty() << endl;

    // Print without destroying original stack
    stack<int> temp = st;

    cout << "Stack elements: ";
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Swap example
    stack<int> st1, st2;

    st1.push(100);
    st2.push(200);

    st1.swap(st2);

    cout << "Top of st1 after swap: " << st1.top() << endl; // 200
}

int main(){
    explainStack();
    return 0;
}