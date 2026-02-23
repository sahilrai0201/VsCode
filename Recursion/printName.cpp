//PRINTING NAME 5 TIMES :

#include<bits/stdc++.h>
using namespace std;

void print(string s, int count){
    if(count == 5) return;

    cout << s << endl;
    print(s, count + 1);
}

int main(){
    string s;
    cout << "Enter the name" << endl;
    cin >> s;

    cout << "I will print the name 5 times : " << endl;
    print(s, 0);     //starts from 0

    return 0;
}