//REVERSE AN ARRAY -> Iterative approach

#include<bits/stdc++.h>
using namespace std;

vector<int> reverse(vector<int> arr, int n){
    int s = 0;
    int e = n-1;
    while(s < e){
        swap(arr[s++], arr[e--]);
    }
    return arr;
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

    vector<int> result = reverse(arr1, n);

    cout << "Reversed array is : ";
    for(int i=0; i<n; i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}