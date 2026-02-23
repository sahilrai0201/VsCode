//PALINDROMIC STRING : Recursive approach ->
#include<bits/stdc++.h>
using namespace std;

bool palindrome(string &s, int start, int end){
    //Base case
    if(start >= end){
        return true;
    }

    //mismatch found
    if(s[start] != s[end]){
        return false;
    }

    //recursive call
    return palindrome(s, start+1, end-1);
}

int main(){
    string s;
    cout << "Enter the string : " << endl;
    cin >> s;

    if(palindrome(s, 0, s.length()-1)){
        cout << "Yes, its a palindrome" << endl;
    }
    else{
        cout << "Not a palindrome" << endl;
    }
    return 0;
}








//PALINDROMIC STRING : Iterative approach ->
// #include<bits/stdc++.h>
// using namespace std;

// bool palindrome(string s){
//     int n = s.length();
//     int start = 0;
//     int end = n-1;
//     while(start < end){
//         if(s[start] != s[end]){
//             return false;           //mismatch found
//         }
//         start++; end--;
//     }
//     return true;
// }

// int main(){
//     string s;
//     cout << "Enter the string : " << endl;
//     cin >> s;

//     if(palindrome(s)){
//         cout << "Yes, its a palindrome" << endl;
//     }
//     else{
//         cout << "Not a palindrome" << endl;
//     }
//     return 0;
// }