//Create a tree from level order traversal

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

node* buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout << "Enter data for root : " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for : " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for : " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
    return root;
}

int main(){

    node *root = NULL;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    return 0;
}