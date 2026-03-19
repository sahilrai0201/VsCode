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

void inOrder(Node* root){     //LNR
    //base case
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node* root){      //NLR
    //base case
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){      //LRN
    //base case
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //prev level is completely traversed
            cout << endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

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

int main(){
    Node* root = NULL;

    cout << "Enter data to create BST" << endl;
    //10 8 21 7 27 5 4 3 -1
    takeInput(root);
    cout << endl;

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "Printing InOrder" << endl;
    inOrder(root);
    cout << endl << endl;

    cout << "Printing PreOrder" << endl;
    preOrder(root);
    cout << endl << endl;;

    cout << "Printing PostOrder" << endl;
    postOrder(root);
    cout << endl << endl;

    return 0;
}