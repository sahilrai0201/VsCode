//QUESTION - Detect cycle in linked list

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

bool detectCycle(Node* head){
    //empty list - No loop possible
    if(head == NULL){
        return false;
    }
    map<Node*, bool> visited;           

    Node* temp = head;
    while(temp != NULL){

        //cycle is present
        if(visited[temp] == true){
            cout << "cycle is present at element : " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;

    detectCycle(head);
    // print(head);

    return 0;
}