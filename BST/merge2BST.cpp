#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d){
    //base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        root->right = insertIntoBST(root->right, d);
    }
    else{
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

Node* takeInput(){
    int data;
    cin >> data;

    Node* root = NULL;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }

    return root;
}

void inorder(Node* root, vector<int> &in){
    if(root == NULL) return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b){
    vector<int> ans;
    int i=0, j=0;

    while(i < (int)a.size() && j < (int)b.size()){
        if(a[i] < b[j]) ans.push_back(a[i++]);
        else ans.push_back(b[j++]);
    }

    while(i < (int)a.size()) ans.push_back(a[i++]);
    while(j < (int)b.size()) ans.push_back(b[j++]);

    return ans;
}

Node* inorderToBST(int s, int e, vector<int> &in){
    if(s>e) return NULL;

    int mid = (s+e)/2;
    Node* root = new Node(in[mid]);
    root->left = inorderToBST(s, mid-1, in);
    root->right = inorderToBST(mid+1, e, in);

    return root;
}

Node* merge(Node* root1, Node* root2){
    //step 1 : store inorder
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    //step 2 : merge 2 sorted arrays of inorders
    vector<int> mergedArray = mergeArrays(bst1, bst2);

    //step 3 : inorder to bst
    int s=0, e=mergedArray.size()-1;
    return inorderToBST(s, e, mergedArray);
}


int main(){
    cout << "Enter elements of bst1 (-1 to stop) : " << endl;
    //50 40 60 70 -1
    Node* root1 = takeInput();

    cout << "Enter elements of bst2 (-1 to stop) : " << endl;
    //55 45 65 35 47 -1
    Node* root2 = takeInput();

    Node* mergeRoot = merge(root1, root2);

    cout << "Inorder of merged BST " << endl;
    vector<int> ans;
    inorder(mergeRoot, ans);

    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}