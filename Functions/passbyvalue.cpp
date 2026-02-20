//Pass by value

#include<bits/stdc++.h>
using namespace std;

void doSomething(int num){
    cout << num << endl;
    num = num + 5;
    cout << num << endl;
    num = num + 5;
    cout << num << endl;
}

int main(){
    int number = 10;
    doSomething(number);

    cout << number << endl;  
    //output : 10, 20, 30, 10(this 10 because of pass by value)
    //copy of number is passed but not original number that's why changes are done only in the copy of number

    return 0;
}