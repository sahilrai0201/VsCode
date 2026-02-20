//COUNT ALL DIGITS OF A NUMBER

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number : " << endl;
    cin >> n;
    
    int count = 0;
    while(n != 0){
        int digit = n % 10;
        count++;
        n = n / 10;
    }
    
    cout << "The total number of digits in n is : " << count << endl;

    return 0;
}