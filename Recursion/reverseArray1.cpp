//REVERSE AN ARRAY -> Recursive approach

#include<bits/stdc++.h>
using namespace std;

void reverseArr(vector<int> &arr, int start, int end){
    //base case
    if(start >= end){
        return;
    }

    //swap
    swap(arr[start], arr[end]);

    //recursive call
    reverseArr(arr, start + 1, end - 1);
}

int main(){
    int n;
    cout << "Enter the size of an array : " << endl;
    cin >> n;

    vector<int> arr1(n);
    cout << "Enter the elements of an array : ";
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }

    //Function call
    reverseArr(arr1, 0, n-1);

    cout << "Reversed array is : ";
    for(int i=0; i<n; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;

    return 0;
}