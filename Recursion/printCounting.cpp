#include<iostream>
using namespace std;

void printCounting(int n){
    //base case
    if(n==0){
        return;
    }
    cout << n << endl;
    printCounting(n-1);
}

int main(){
    int n;
    cout << "Enter the number : " << endl;
    cin >> n;
    cout << endl;
    
    printCounting(n);
    return 0;
}
