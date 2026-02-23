//PRINT ALL DIVISORS OF A NUMBER : 

#include<bits/stdc++.h>
using namespace std;

vector<int> divisor(int n){
    vector<int> small, large;

    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            small.push_back(i);

            if(i != n/i){
                large.push_back(n/i);
            }
        }
    }

    vector<int> ans;

    for(int x : small){
        ans.push_back(x);
    }
    for(int i=large.size()-1; i>=0; i--){
        ans.push_back(large[i]);
    }

    return ans;
}

int main(){
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;

    vector<int> result = divisor(num);

    cout << "All the divisors of given number is as follows : ";
    for(int x : result){
        cout << x << " ";
    }

    return 0;
}