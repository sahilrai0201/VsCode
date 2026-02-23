#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int n, int k){
    int ans = -1;
    int start = 0;
    int end = n-1;

    int mid = start + (end - start) / 2;
    while(start <= end){
        if(arr[mid] == k){
            ans = mid;
            end = mid - 1;
        }
        else if(arr[mid] > k){
            end = mid - 1;
        }
        else{
            //arr[mid] < k
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter the size of an array : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of an array : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target that to be searched in array : " << endl;
    cin >> target;

    int result = binarySearch(arr, n, target);

    cout << "After applying binary search on the given array, target is at index : " << result << endl;
}