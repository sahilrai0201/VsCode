//Check Sum tree problem

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

//function to create tree : 
Node *buildTree(Node *root){

    cout << "Enter the data : " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data for inserting in left :" << " " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right :" << " " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

//function to check sum tree : 
pair<bool, int> isSumTree(Node* root){
    //base case
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    //leaf node
    if(root->left == NULL && root->right == NULL){
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    //recursive calls
    pair<bool, int> leftAns = isSumTree(root->left);
    pair<bool, int> rightAns = isSumTree(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condition = root->data == leftAns.second + rightAns.second;

    pair<bool, int> ans;

    if(left && right && condition){
        ans.first = true;
        ans.second = 2 * root->data;      //2 * root->data = root->data + leftAns.second + rightAns.second
    }
    else{
        ans.first = false;
    }
    return ans;
}

int main(){
    Node *root = NULL;

    //ceating a tree
    root = buildTree(root);     //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //check sum tree
    pair<bool, int> result = isSumTree(root);
    if(result.first){
        cout << "Tree is a sum tree" << endl;
    }
    else{
        cout << "Tree is not a sum tree" << endl;
    }
    
    return 0;
}