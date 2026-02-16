//REVERSE LEVEL ORDER TRAVERSAL

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
    stack<node*> st;   // added stack

    q.push(root);
    q.push(NULL);      // separator

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            st.push(temp);   // instead of printing, push into stack

            // IMPORTANT: push right first for correct order
            if(temp->right){
                q.push(temp->right);
            }

            if(temp->left){
                q.push(temp->left);
            }
        }
    }

    // Now print in reverse order
    while(!st.empty()){
        cout << st.top()->data << " ";
        st.pop();
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