//return max of 2 numbers

#include<bits/stdc++.h>
using namespace std;

int maxi(int a, int b){
    if(a >= b) return a;
    else return b;
}

int main(){
    int num1;
    cout << "Enter the number 1 : " << endl;
    cin >> num1;

    int num2;
    cout << "Enter the number 2 : " << endl;
    cin >> num2;

    int result = maxi(num1, num2);

    cout << "Maximum of two numbers is : " << result << endl;

    return 0;
}