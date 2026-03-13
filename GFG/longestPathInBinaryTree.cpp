//Sum of nodes on the longest path ->//Given a binary tree root[], you need to find the sum of the nodes on the longest path from the 
//root to any leaf node. If two or more paths have the same length, the path with the maximum sum 
//of node values should be considered.

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right =  NULL;
    }
};

void solve(Node* root, int sum, int &maxSum, int len, int &maxLen){
    //base case
    if(root == NULL){
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen){
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum = sum + root->data;

    solve(root->left, sum, maxSum, len+1, maxLen);
    solve(root->right, sum, maxSum, len+1, maxLen);
}

int sumOfLongRootToLeafPath(Node* root){
    int sum = 0;
    int maxSum = INT_MIN;

    int len = 0;
    int maxLen = 0;

    solve(root, sum, maxSum, len, maxLen);

    return maxSum;
} 

int main(){
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int result = sumOfLongRootToLeafPath(root);
    cout << "Sum of nodes of longest path from root to leaf is : " << result << endl;

    return 0;
}