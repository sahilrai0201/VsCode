//Given an array, answer multiple queries asking: How many times does a number appear in array?

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of an array : " << endl;
    cin >> n;

    // Declaring array of size n
    // (Note: Variable Length Array works in GCC, but vector is safer in standard C++)
    int arr[n];

    cout << "Enter the elements of an array : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];   // Taking array input
    }

    // PRECOMPUTATION (HASHING STEP)

    // Creating a hash array of size 13, This will store frequency of numbers from 0 to 12
    // hash[i] = how many times 'i' appears in the array
    int hash[13] = {0};  // Initially all values are 0

    for(int i=0; i<n; i++){
        // Increase frequency of element arr[i]
        hash[arr[i]] += 1;
    }

    // QUERY PART
    int q;
    cout << "Enter the number of queries : " << endl;
    cin >> q;

    cout << "Enter the queries : " << endl;

    while(q--){
        int number;
        cin >> number;   // Number whose frequency we want

        // Fetching frequency in O(1) time
        cout << hash[number] << endl;
    }

    return 0;
}