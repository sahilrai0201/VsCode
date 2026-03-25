#include<bits/stdc++.h>
using namespace std;

// Node of Trie
class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

// Trie class
class Trie{
public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    // INSERT ------------------------
    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        for(char &c : word) c = tolower(c);
        insertUtil(root, word);
    }

    // SEARCH ------------------------
    bool searchUtil(TrieNode* root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'a';

        if(root->children[index] == NULL){
            return false;
        }

        return searchUtil(root->children[index], word.substr(1));
    }

    bool searchWord(string word){
        for(char &c : word) c = tolower(c);
        return searchUtil(root, word);
    }

    // DELETE ------------------------
    bool isEmpty(TrieNode* node){
        for(int i = 0; i < 26; i++){
            if(node->children[i] != NULL){
                return false;
            }
        }
        return true;
    }

    TrieNode* removeUtil(TrieNode* node, string word){
        if(node == NULL) return NULL;

        // base case
        if(word.length() == 0){
            node->isTerminal = false;

            if(isEmpty(node)){
                delete node;
                return NULL;
            }
            return node;
        }

        int index = word[0] - 'a';

        node->children[index] = removeUtil(node->children[index], word.substr(1));

        // IMPORTANT: do not delete root
        if(node != root && isEmpty(node) && node->isTerminal == false){
            delete node;
            return NULL;
        }

        return node;
    }

    void removeWord(string word){
        for(char &c : word) c = tolower(c);
        root = removeUtil(root, word);
    }
};

int main(){

    Trie* t = new Trie();

    // inserting words
    t->insertWord("abcd");
    t->insertWord("DO");
    t->insertWord("TIME");
    t->insertWord("LOVE");

    // search before delete
    cout << "TIME present: " << t->searchWord("TIME") << endl;

    // delete word
    t->removeWord("TIME");

    // search after delete
    cout << "TIME present after delete: " << t->searchWord("TIME") << endl;

    // prefix check
    cout << "TIM present: " << t->searchWord("TIM") << endl;

    return 0;
}