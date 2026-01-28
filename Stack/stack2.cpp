// STACK IMPLEMENTATION USING LINKED LIST

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
    // properties
    Node* top;

public:
    // constructor
    Stack() {
        top = NULL;
    }

    // push operation
    void push(int element) {
        Node* newNode = new Node(element);
        newNode->next = top;
        top = newNode;
    }

    // pop operation
    void pop() {
        if(top == NULL) {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // peek operation
    int peek() {
        if(top == NULL) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

    // isEmpty operation
    bool isEmpty() {
        return top == NULL;
    }
};

int main() {

    Stack st;

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(55);
    st.push(66);
    st.push(77);   // No overflow in LL stack

    cout << "Top element is: " << st.peek() << endl;

    st.pop();
    cout << "Top element is: " << st.peek() << endl;

    st.pop();
    cout << "Top element is: " << st.peek() << endl;

    st.pop();
    cout << "Top element is: " << st.peek() << endl;

    if(st.isEmpty()){
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}
