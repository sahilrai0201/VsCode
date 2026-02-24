//We are counting how many times each letter appears in a string
//and then answering queries in constant time.

#include<bits/stdc++.h>
using namespace std;

int main(){

    // Variable to store input string
    string s;

    cout << "Enter the string : " << endl;
    cin >> s;   // Taking string input (assumes lowercase letters)

    // PRECOMPUTATION (HASHING STEP) 

    // Creating a hash array of size 26
    // Each index represents a lowercase character:
    // index 0 -> 'a'
    // index 1 -> 'b'
    // ...
    // index 25 -> 'z'
    int hash[26] = {0};   // Initially all frequencies are 0

    // Loop through the string and count frequency of each character
    for(int i = 0; i < s.size(); i++){

        // s[i] - 'a' converts character into index
        // Example:
        // 'a' - 'a' = 0
        // 'b' - 'a' = 1
        // 'c' - 'a' = 2

        hash[s[i] - 'a']++;   // Increase frequency of that character
    }

    // QUERY PART 

    int q;
    cout << "Enter the number of queries : " << endl;
    cin >> q;   // Number of characters we want to check

    cout << "Enter queries : " << endl;

    while(q--){
        char c;
        cin >> c;   // Character whose frequency we want

        // Fetch frequency in O(1) time
        cout << hash[c - 'a'] << endl;
    }

    return 0;
}