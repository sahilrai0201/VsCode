//LEVEL ORDER TRAVERSAL

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

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if(temp->left){  //left is non-null
            q.push(temp->left);
        }

        if(temp->right){  //right is non-null
            q.push(temp->right);
        }
    }
}

int main(){

    node *root = NULL;

    //ceating a tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    

    //level order
    cout << "Printing the level order traversal output : " << endl;
    levelOrderTraversal(root);


    return 0;
}