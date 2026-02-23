//CHECK IF A NUMBER IS ARMSTRONG OR NOT : 

#include<bits/stdc++.h>
using namespace std;

int power(int base, int exp){
    int result = 1;
    while(exp--){
        result *= base;
    }
    return result;
}

bool armstrong(int n){
    int original = n;
    int temp = n;
    int count = 0;

    //step1: count digits
    while(temp > 0){
        count++;
        temp /= 10;
    }

    temp = n;
    int sum = 0;

    //step2: find sum of digits^count
    while(temp > 0){
        int digit = temp % 10;
        sum += power(digit, count);
        temp /= 10;
    }

    //step3: compare 
    return sum == original;
}

int main(){
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;

    bool result = armstrong(num);
    if(result == true){
        cout << "Given number ia an armstrong number!" << endl;
    }
    else{
        cout << "Not an armstrong number!" << endl;
    }

    return 0;
}