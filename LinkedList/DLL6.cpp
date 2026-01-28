//DELETION - DOUBLY LINKED LIST

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

    //destructor
    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory is freed for the node with data : " << val << endl;
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
void insertAtHead(Node* &tail, Node* &head, int d){

    //*empty list*
    if(head == NULL){
        Node* temp  = new Node(d);
        head = temp; 
        tail = temp;
    }
    else{
        Node* temp  = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp; 
    } 
}

//insertion at tail
void insertAtTail(Node* &tail, Node* &head, int d){
    //*empty list*
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

//insertion at any position in the middle
void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    //insert at start
    if(position == 1){
        insertAtHead(tail, head, d);
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
        insertAtTail(tail, head, d);
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

void deleteNode(int position, Node* &head, Node* &tail){
    //deleting first node
    if(position == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;     //deleting through destructor
    }
    else {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        //check if we deleted the LAST NODE
        if(curr->next == NULL){
            tail = prev;     // update tail
        }
        curr->next = NULL;
        delete curr;
        
    }
}

int main(){

    //*LL is empty, head & tail are marked null*
    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    cout << "length is : " << getLength(head) << endl;

    insertAtHead(tail, head, 11);
    print(head);

    insertAtHead(tail, head, 13);
    print(head);
    
    insertAtHead(tail, head, 8);
    print(head);

    insertAtTail(tail, head, 25);
    print(head);

    insertAtPosition(head, tail, 2, 100);
    print(head);

    insertAtPosition(head, tail, 1, 101);
    print(head);

    insertAtPosition(head, tail, 7, 102);
    print(head);

    deleteNode(7, head, tail);
    print(head);

    return 0;
}