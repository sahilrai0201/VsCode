#include<bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int> &arr, int n){
    unordered_map<int, int> count;

    int maxFreq = 0;
    int maxAns = 0;

    for(int i=0; i<n; i++){
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]); 
    }

    for(int i=0; i<n; i++){
        if(maxFreq == count[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}

int main(){

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";          
    //1 2 2 3 1 2
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = maxFrequency(arr, n);

    cout << "Element with maximum frequency: " << ans << endl;

    return 0;
}