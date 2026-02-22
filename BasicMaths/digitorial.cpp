//Digitorial permutation or Strong number

#include<bits/stdc++.h>
using namespace std;

bool digitorialPermutation(int n){
    //precompute factorial of digit 0-9
    int fact[10];
    fact[0] = 1;
    for(int i=1; i<=9; i++){
        fact[i] = fact[i-1] * i;
    }

    //count digits of n
    vector<int> freqN(10, 0);
    int temp = n;
    while(temp > 0){
        freqN[temp % 10]++;
        temp /= 10;
    }

    //count sum of factorials
    long long sumFact = 0;
    temp = n;
    while(temp > 0){
        sumFact += fact[temp % 10];
        temp /= 10;
    }

    //count digits of sumfact
    vector<int> freqSum(10, 0);
    temp = sumFact;
    if(temp == 0) freqSum[0]++;
    while(temp > 0){
        freqSum[temp % 10]++;
        temp /= 10;
    }

    //compare digit frequencies
    return freqN == freqSum;
}

int main(){
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;

    int result = digitorialPermutation(num);

    if(result == true){
        cout << "num is a digitorial number or strong number!" << endl;
    }
    else{
        cout << "num  is not a strong number" << endl;
    }

    return 0;
}