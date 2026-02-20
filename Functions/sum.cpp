//take 2 numbers & print their sum

#include<bits/stdc++.h>
using namespace std;

int sum(int a, int b){
    return a + b;
}

int main(){
    int x;
    cout << "Enter the number x : " << endl;
    cin >> x;

    int y; 
    cout << "Enter the number y : " << endl;
    cin >> y;

    int result = sum(x, y);
    cout << "The sum of x & y is : " << result << endl;

    return 0;
}