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
        //insert in right part
        root->right = insertIntoBST(root->right, d);
    }
    else{
        //insert in left part
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

Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

int main(){
    Node* root = NULL;

    cout << "Enter data to create BST" << endl;
    //10 8 21 7 27 5 4 3 -1
    takeInput(root);

    if(root == NULL){
        cout << "Tree is empty" << endl;
        return 0;
    }

    cout << "Min val is : " << minVal(root)->data << endl;
    cout << "Max val is : " << maxVal(root)->data << endl;

    return 0;
}