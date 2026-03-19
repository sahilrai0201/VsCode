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

void inOrder(Node* root){
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
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

Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int target){
    //base case
    if(root == NULL) return root;

    if(root->data == target){
        //0 child -> leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child -> left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //1 child -> right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    else if(root->data > target){
        //left part
        root->left = deleteFromBST(root->left, target);
        return root;
    }

    else{
        //right part
        root->right = deleteFromBST(root->right, target);
        return root;
    }    
    return root;
}

int main(){
    Node* root = NULL;

    cout << "Enter data to create BST" << endl;
    // 100 50 25 60 70 110 120 115 -1
    takeInput(root);
    cout << endl;

    cout << "Inorder traversal before deletion" << endl;
    inOrder(root);
    cout << endl;

    int target;
    cout << "Enter the node to be deleted : " << endl;
    cin >> target;

    root = deleteFromBST(root, target);

    cout << "Inorder traversal after deletion" << endl;
    inOrder(root);
    cout << endl;

    return 0;
} 