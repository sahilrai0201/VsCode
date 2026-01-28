//INSERTION AT HEAD - DOUBLY LINKED LIST

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

//traversing a linked list
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//finding lenght of a linked list
int getLength(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

//insertion at head
void insertAtHead(Node* &head, int d){
    Node* temp  = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;  
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;

    print(head);
    cout << "length is : " << getLength(head) << endl;

    insertAtHead(head, 11);
    print(head);

    insertAtHead(head, 13);
    print(head);
    
    insertAtHead(head, 8);
    print(head);

    return 0;
}