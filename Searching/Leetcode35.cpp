//Binary search approach -> 

#include<iostream>
#include<vector>
using namespace std;

int searchInsert(int arr[], int n, int target){
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;

    while(start<=end){
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return start;
}

int main(){
    int arr[4] = {1, 3, 5, 6};
    int target;
    cout<<"enter the target : "<<endl;
    cin>>target;

    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = searchInsert(arr, n, target);
    cout << ans << endl;

    return 0;
}
