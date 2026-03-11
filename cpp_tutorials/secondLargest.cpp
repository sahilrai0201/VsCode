//Given an array of positive integers arr[], return the second largest element from the array. 
//If the second largest element doesn't exist then return -1.
//Note: The second largest element should not be equal to the largest element.

#include<bits/stdc++.h>
using namespace std;

int secondLargest(vector<int> &arr){
    long long first = LLONG_MIN;
    long long second = LLONG_MIN;

    for(int x : arr){
        //skips duplicates
        if(x == first || x == second) continue;

        if(x > first){
            second = first;
            first = x;
        }
        else if(x > second && x != first){
            second = x;
        }
    }
    return (second == LLONG_MIN) ? -1 : second;
}

int main(){
    int n;
    cout << "Enter size : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements of array : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << endl;

    int result = secondLargest(arr);

    cout << "The second latrgest element is : " << result << endl;

    return 0;
}