//STACK OPERATIONS/IMPLEMENTATION USING ARRAY FOR DEFINIG CLASS STACK: 

#include<bits/stdc++.h>
using namespace std;

class Stack{
    //properties
    int *arr;
    int top;
    int size;

public:
    //behaviors
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        } else {
            cout << "Stack Underflow" << endl;
        }
    }           

    int peek(){
        if(top >= 0){
            return arr[top];
        } else {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty(){
        return top == -1;
    }
    
};

int main(){

    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(55);
    st.push(66);
    st.push(77); // This should show Stack Overflow
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