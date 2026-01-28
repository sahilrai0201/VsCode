//INSERTION - Circular LL

#include<iostream>
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

void insertNode(Node* &tail, int element, int d){
    //empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list!

        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }

        //element found - curr is representing the element's node
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* &tail){     //list traversal
    Node* temp = tail;
    do{
        cout << tail->data << " ";
        tail = tail->next;
    } while(tail  != temp);
    cout << endl;
}

int main(){

    Node* tail = NULL;

    //insertion in empty list
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 6);
    print(tail);

    insertNode(tail, 6, 9);
    print(tail);

    insertNode(tail, 6, 7);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    return 0;
}