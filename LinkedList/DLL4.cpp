//INSERTION AT ANY POSITION - DOUBLY LINKED LIST

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

//insertion at tail
void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

//insertion at any position in the middle
void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    //insert at start
    if(position == 1){
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position-1){
        temp = temp->next;
        count++;
    }

    //insert at last
    if(temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }

    //insert in middle
    //create a new node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout << "length is : " << getLength(head) << endl;

    insertAtHead(head, 11);
    print(head);

    insertAtHead(head, 13);
    print(head);
    
    insertAtHead(head, 8);
    print(head);

    insertAtTail(tail, 25);
    print(head);

    insertAtPosition(head, tail, 2, 100);
    print(head);

    insertAtPosition(head, tail, 1, 101);
    print(head);

    insertAtPosition(head, tail, 8, 102);
    print(head);

    return 0;
}