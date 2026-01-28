//DELETION - Singly linked list

#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node* &head, int d){      //Insertion at head
    //new node creation
    Node* temp = new Node(d);

    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){      //Insertion at tail
    //new node creation
    Node* temp = new Node(d);

    tail->next = temp;
    tail = temp;
}

void print(Node* &head){         //printing the LL

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d){

    if(position == 1){       //to insert at first node
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position-1){
        temp = temp->next;
        count++;
    }

    //insert at last position
    if(temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node* &head, Node* &tail){
    //deleting first node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        //memory free for start node
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
        prev->next = curr->next;
        //check if we deleted the LAST NODE
        if(curr->next == NULL){
            tail = prev;     // update tail
        }
        curr->next = NULL;
        delete curr;
        
    }
}

int main(){

    //created a new node
    Node* node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    //head is pointed to the new node
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(tail, head, 4, 22);    //op: [10 12 15 22]
    print(head);

    // cout << "head is : " << head->data << endl;
    // cout << "tail is : " << tail->data << endl;

    deleteNode(4, head, tail);       //op: [10, 12, 15]
    print(head);

    cout << "head is : " << head->data << endl;           //head: 10
    cout << "tail is : " << tail->data << endl;        //tail: 15

    return 0;
}