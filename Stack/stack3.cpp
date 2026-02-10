//Reverse a string using stack : 
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "HelloWorld";
    stack<char> s;

    for(char ch : str){
        s.push(ch);
    }

    string reversedStr = "";
    while(!s.empty()){
        reversedStr += s.top();
        s.pop();
    }

    cout << "Original String: " << str << endl;
    cout << "Reversed String: " << reversedStr << endl;
    return 0;
}