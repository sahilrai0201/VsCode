//FIND DUPLICATES IN AN ARRAY

#include<bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &arr, int n){
    vector<int> ans;

    for(int i = 0; i < n; i++){
        int index = abs(arr[i]) - 1;

        if(arr[index] < 0){
            ans.push_back(index + 1);
        } else {
            arr[index] = -arr[index];
        }
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    vector<int> result = findDuplicates(arr, n);

    cout << "Duplicates in the array are : ";
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}