#include<bits/stdc++.h>
using namespace std;

int reverse(int n){
    int rev = 0;
    while(n > 0){
        if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && n % 10 > 7)){
            return 0; // Overflow case for positive numbers
        }
        rev = rev * 10 + n % 10;
        n = n / 10;
    }
    return rev;
}

int main(){
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;
    
    int result = reverse(num);

    cout << "Reversed number is : " << result << endl;

    return 0;
}