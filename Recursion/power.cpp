#include<iostream>
using namespace std;

int power(int n){

    //base case
    if(n==0){
        return 1;
    }

    //recursive relation
    return 2 * power(n-1);
}

int main(){

    int n;
    cout << "enter the number : " << endl;
    cin >> n;

    int ans = power(n);
    cout << "2 raises to power n is : " << ans <<endl;
    return 0;
}
