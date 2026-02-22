//GCD of 2 numbers

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int n;
    cout << "Enter the size of an array : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements of an array : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int num : arr){
        mini = min(mini, num);
        maxi = max(maxi, num);
    }

    int result = gcd(mini, maxi);
    cout << "The gcd of max & min element of an array is : " << result << endl;

    return 0;
}





//if we have to find gcd of all the elements of an array : (GFG) ->

// class Solution {
//   public:
//     int findGCD(int a, int b){
//         if(b == 0) return a;
//         return findGCD(b, a % b);
//     }

//     int gcd(int n, vector<int> arr) {
//         int result = arr[0];

//         for(int i = 1; i < n; i++){
//             result = findGCD(result, arr[i]);
//         }

//         return result;
//     }
// };