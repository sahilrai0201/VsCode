//Pass by reference

#include<bits/stdc++.h>
using namespace std;

void doSomething(int &num){
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
    //output : 10, 20, 30, 20(this 20 because of pass by reference)
    //original number is passed (through '&' operator) but not copy of number 
    //that's why changes are done directly in the number

    return 0;
}