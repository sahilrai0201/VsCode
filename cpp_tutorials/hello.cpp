#include<iostream>
using namespace std;

int factorial(int n){

    //base case
    if(n==0){
        return 1;
    }

    //recursive case
    int chhoti = factorial(n-1);
    int badi = n * chhoti;
    return badi;
}
int main(){
    int n;
    cout<<"enter the value of which you need to find the factorial : "<<endl;
    cin>>n;

    int ans = factorial(n);
    cout<<"the factorial of given number is : "<<ans<<endl;
}