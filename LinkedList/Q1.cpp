//QUESTION - Check if the list is circular or not?

#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data : " << value << endl;
    }
};

bool isCircularList(Node* head){

    //empty list
    if(head == NULL){
        return true;
    }

    Node* temp = head->next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }

    if(temp == head) return true;
    
    return false;
}

int main(){
    /*
    //singly LL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = NULL; 
    */

    //circular LL
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    head->next = second;
    second->next = third;
    third->next = head;

    if(isCircularList(head)){
        cout << "LL is circular" << endl;
    } else{
        cout << "Not circular" << endl;
    }

    return 0;
}