//CHECK IF A NUMBER IS PRIME OR NOT: 

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n <= 1) return false;
    if(n == 2) return true;

    for(int i=2; i*i<=n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;

    bool result = isPrime(num);
    if(result == true){
        cout << "Given number is prime" << endl;
    }
    else{
        cout << "Given number is not prime" << endl;
    }

    return 0;
}