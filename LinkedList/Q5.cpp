//QUESTION - Remove cycle in Linked list

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

/*
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
*/

Node* flyodDetectLoop(Node* head){
    //empty list
    if(head == NULL)
        return NULL;
    
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast){
            //loop detected
            // cout << "cycle present at node : " << slow->data << endl;          //we can write fast->data also
            return slow;
        }
    }
    return NULL;    //No cycle detected
}

Node* getstartingNode(Node* head){
    if(head == NULL) return NULL;

    Node* intersection = flyodDetectLoop(head);
    Node* slow = head;
    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

void removeLoop(Node* head){
    if(head == NULL) return;

    Node* startOfLoop = getstartingNode(head);
    Node* temp = startOfLoop;

    while(temp->next != startOfLoop){
        temp = temp->next;
    }
    temp->next = NULL;
}

void print(Node* &head){
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

    /*
    if(flyodDetectLoop(head) != NULL){
        cout << "cycle present" << endl;
    } else{
        cout << "cycle not present" << endl;
    } 
    */

    /*
    Node* loop = flyodDetectLoop(head);
    cout << "loop starts at : " << loop->data << endl;
    */

    removeLoop(head);
    print(head);

    return 0;
}