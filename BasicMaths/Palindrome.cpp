//PALINDROME OR NOT

#include<bits/stdc++.h>
using namespace std;

bool palindrome(int n){
    // Negative numbers and numbers ending with 0 (but not 0) are not palindromes
    if(n < 0 || (n % 10 == 0 && n != 0)){
        return false;
    }

    int reversedHalf = 0;
    while(n > reversedHalf){
        reversedHalf = reversedHalf * 10 + n % 10;
        n = n / 10;
    }

    // If x is equal to reversedHalf (even length)
    // or x is equal to reversedHalf / 10 (odd length, middle digit ignored)
    return (n == reversedHalf || n == reversedHalf / 10);
}

int main(){
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;
    
    bool result = palindrome(num);

    if(result == true){
        cout << "Given number is Palindrome" << endl;
    }
    else{
        cout << "Not palindrome" << endl;
    }
    return 0;
}