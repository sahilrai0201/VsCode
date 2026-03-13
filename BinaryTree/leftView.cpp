#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void solve(Node* root, vector<int> &ans, int level){
    // base case
    if(root == NULL) return;

    // we entered a new level
    if(level == (int)ans.size()){
        ans.push_back(root->data);
    }

    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}

vector<int> leftView(Node* root){
    vector<int> ans;
    solve(root, ans, 0);     // root, ans, level
    return ans;
}

int main(){
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(5);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->left->right->right = new Node(7);

    root->right->right = new Node(6);

    root->right->right->right = new Node(8);

    root->right->right->right->right = new Node(9);

    vector<int> result = leftView(root);
    cout << "Left view of the given tree is : " << endl;
    for(int i : result){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}