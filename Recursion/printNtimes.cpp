//PRINTING 1 N NUMBER OF TIMES -> LEADS TO STACK OBVERFLOW

#include<bits/stdc++.h>
using namespace std;

void print(){
    cout << 1 << endl;
    print();
}

int main(){
    print();

    return 0;
}