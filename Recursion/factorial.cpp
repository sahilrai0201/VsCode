#include<iostream>
using namespace std;

int factorial(int n){

    //base case
    if(n==0){
        return 1;
    }

    return n * factorial(n-1);
}

int main(){
    int n;
    cout << "enter the numbner of which you want to find the factorial : " << endl;
    cin >> n;

    int ans = factorial(n);
    cout << "factorial of the given nnumber is : " << ans << endl;
    return 0;
}
