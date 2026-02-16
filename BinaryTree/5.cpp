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

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);

    q.push(NULL);      //separator

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){     //traversal of prev level is completed
            cout << endl;
            if(!q.empty()){       //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){  //left is non-null
                q.push(temp->left);
            }

            if(temp->right){  //right is non-null
                q.push(temp->right);
            }
        }
    }
}

void inOrder(node* root){     //LNR
    //base case
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
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
    

    //level order
    cout << "Printing the level order traversal output : " << endl;
    levelOrderTraversal(root);
    cout << endl;


    //Inorder traversal
    cout << "Inorder traversal is : " << endl;
    inOrder(root);
    cout << endl;
    cout << endl;

    //Preorder traversal
    cout << "Preorder traversal is : " << endl;
    preOrder(root);
    cout << endl;
    cout << endl;

    return 0;
}