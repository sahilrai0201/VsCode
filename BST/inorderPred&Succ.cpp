#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    //constructor
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d){
    //base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        //right
        root->right = insertIntoBST(root->right, d);
    }
    else{
        //left
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

vector<Node*> predSucc(Node* root, int key){
    Node* temp = root;
    Node* pred = NULL;
    Node* succ = NULL;

    // Step 1: Find the key node while updating pred & succ
    while(temp != NULL && temp->data != key){
        if(temp->data > key){
            succ = temp;
            temp = temp->left;
        }
        else{
            pred = temp;
            temp = temp->right;
        }
    }
    //if key not found
    if(temp == NULL) return {pred, succ};

    // Step 2: Find predecessor (max in left subtree)
    Node* leftTree = temp->left;
    while(leftTree != NULL){
        pred = leftTree;
        leftTree = leftTree->right;
    }

    // Step 3: Find successor (min in right subtree)
    Node* rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree;
        rightTree = rightTree->left;
    }

    return {pred, succ};
}

int main(){
    Node* root = NULL;

    cout << "Enter the data to create a BST (-1 for null) : " << endl;
    // 50 30 70 20 40 60 80 -1
    takeInput(root);

    int key;
    cout << "Enter key for which you want predeccessor and successor : " << endl;
    cin >> key;

    vector<Node*> result = predSucc(root, key);
    cout << "Predeccessor and Successor of the given key is : " << endl;
    for(auto i : result){
        if(i != NULL){
            cout << i->data << " ";
        }
        else{
            cout << "NULL ";
        }
    }
    cout << endl;


    return 0;
}