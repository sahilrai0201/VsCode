//FIND SUM OF FIRST N NUMBERS

#include<bits/stdc++.h>
using namespace std;

int sumN(int n){
    //base case
    if(n == 0){
        return 0;
    }

    //recursive case
    return n + sumN(n-1);
}

int main(){
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;

    int result = sumN(num);
    cout << "Sum of first N number is : " << result << endl;

    return 0;
}