//Given a string s which consists of lowercase or uppercase letters, 
//return the length of the longest palindrome that can be built with those letters.

#include<bits/stdc++.h>
using namespace std;

int longestPalindrome(string &s){
    vector<int> freq(128, 0);

    for(char c : s){
        freq[c]++;
    }

    int length = 0;
    bool hasOdd = false;

    for(int count : freq){
        if(count % 2 == 0){
            length += count;
        }
        else{
            length += count - 1;
            hasOdd = true;
        }
    }

    if(hasOdd) length += 1;
    return length;
}

int main(){
    string s;
    cout << "Enter the string : " << endl;
    cin >> s;

    int result = longestPalindrome(s);
    cout << "The longest palindromic length is : " << result << endl;

    return 0;
}