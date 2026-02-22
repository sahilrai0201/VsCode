//Given a positive integer n, find and return the longest distance between any two adjacent 
//1's in the binary representation of n. If there are no two adjacent 1's, return 0.

//Two 1's are adjacent if there are only 0's separating them (possibly no 0's). 
//The distance between two 1's is the absolute difference between their bit positions. 
//For example, the two 1's in "1001" have a distance of 3.

#include<bits/stdc++.h>
using namespace std;

int binaryGap(int n){
    int prev = -1;
    int maxGap = 0;
    for(int i=0; n>0; i++){
        if(n & 1){
            if(prev != -1){
                maxGap = max(maxGap, i-prev);
            }
            prev = i;
        }
        n = n >> 1;
    }
    return maxGap;
}

int main(){
    int num;
    cout << "Enter the number in which you want maxGap : " << endl;
    cin >> num;

    int result = binaryGap(num);
    cout << "The max gap between two consecutive ones in a num is : " << result << endl;

    return 0;
}