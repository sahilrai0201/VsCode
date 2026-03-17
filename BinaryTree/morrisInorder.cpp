#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(){
    int data;
    cin >> data;

    if(data == -1) return NULL;

    Node* root = new Node(data);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

vector<int> morrisInorder(Node* root){
    vector<int> result;
    Node* curr = root;

    while(curr != NULL){
        if(curr->left == NULL){
            result.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* pred = curr->left;

            //find rightmost node
            while(pred->right && pred->right != curr){
                pred = pred->right;
            }

            if(pred->right == NULL){
                //create thread
                pred->right = curr;
                curr = curr->left;
            }
            else{
                //remove thread
                pred->right = NULL;
                result.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return result;
}

int main(){
    cout << "Enter nodes data in preOrder (-1 for null) : " << endl;
    //1 2 4 -1 7 -1 -1 5 -1 -1 3 -1 6 -1 -1

    Node* root = buildTree();

    vector<int> ans = morrisInorder(root);
    cout << "Morris Inorder traversal for the given tree is : " << endl;
    for(auto i : ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}