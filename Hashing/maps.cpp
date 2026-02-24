//“Given an array, answer multiple queries of frequency of elements.”

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of an array : " << endl;
    cin >> n;   // Input size of array

    // Declaring array of size n
    int arr[n];

    cout << "Enter the elements of an array : " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];   // Taking input for each array element
    }

    // PRECOMPUTATION (HASHING STEP)
    // Creating a map to store frequency of each element
    // key   -> array element
    // value -> frequency of that element
    map<int, int> mpp;

    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;   // Increase frequency of arr[i] by 1
        // If key doesn't exist, map initializes it to 0 first
    }

    // for(auto it : mpp){        //map stores data in sorted order
    //     cout << it.first << "->" << it.second << endl;
    // }

    // QUERY PART
    int q;
    cout << "Enter the number of queries : " << endl;
    cin >> q;   // Number of frequency queries

    cout << "Enter the queries : " << endl;
    while(q--){
        int number;
        cin >> number;   // Number whose frequency we want to check

        // Fetching frequency from map
        // If number is not present, it returns 0
        cout << mpp[number] << endl;
    }
    return 0;
}