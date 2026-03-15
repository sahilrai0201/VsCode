//Given a binary tree of size  n, a node, and a positive integer k. 
//Your task is to complete the function kthAncestor(), the function should return the kth ancestor 
//of the given node in the binary tree. If there does not exist any such ancestor then return -1.
//Note: 1. It is guaranteed that the node exists in the tree.
//2. All the nodes of the tree have distinct values.

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

bool findPath(Node* root, int node, vector<int> &path){
    if(root == NULL) return false;

    //add current node
    path.push_back(root->data);

    //node found
    if(root->data == node) return true;

    //search left or right
    if(findPath(root->left, node, path) || findPath(root->right, node, path)) return true;

    //backtrack
    path.pop_back();
    return false;
}

int kthAncestor(Node* root, int k, int node){
    vector<int> path;

    //check if node exists in a tree or not
    if(!findPath(root, node, path)) return -1;

    if((int)path.size() <= k) return -1;

    return path[path.size() - k -1];
}

int main(){
    cout << "Enter elements in preOrder (-1 for null) : " << endl;
    //1 2 4 -1 -1 5 -1 -1 3 -1 -1

    Node* root = buildTree();

    int k;
    cout << "Enter the value of k : " << endl;
    cin >> k;

    int node;
    cout << "Enter the node whom you want kth ancestor : " << endl;
    cin >> node;

    int result = kthAncestor(root, k, node);
    cout << "Kth ancestor of the given node is : " << result << endl;

    return 0;
}