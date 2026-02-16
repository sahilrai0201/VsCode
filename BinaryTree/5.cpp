//PREORDER TRAVERSAL

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;

    //constructor
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }    
};

//function to create tree
node *buildTree(node *root){

    cout << "Enter the data : " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data for inserting in left :" << " " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right :" << " " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void preOrder(node* root){      //NLR
    //base case
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}


int main(){

    node *root = NULL;

    //ceating a tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //Preorder traversal
    cout << "Preorder traversal is : " << endl;
    preOrder(root);
    cout << endl;
    cout << endl;

    return 0;
}