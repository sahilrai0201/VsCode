//FIND FACTORIAL OF A GIVEN NUMBERS : 

#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    //base case
    if(n == 0 || n == 1){
        return 1;
    }

    //recursive call
    return n * fact(n-1);
}

int main(){
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;

    int result = fact(num);
    cout << "Sum of first N number is : " << result << endl;

    return 0;
}