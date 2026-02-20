// PAIRS EXPLANATION

#include<bits/stdc++.h>
using namespace std;

void explainPair(){

    // Method 1 (old style)
    // pair<int, int> p = make_pair(1,3);

    // Method 2 (modern & cleaner)
    pair<int, int> p = {1, 3};

    // Accessing elements using .first and .second
    cout << p.first << " " << p.second << endl;  
    // Output: 1 3


    // Nested pair
    // first = 1
    // second = another pair {3,4}
    pair<int, pair<int, int>> p1 = {1, {3, 4}};

    // Accessing nested pair
    cout << p1.first << " "              // 1
         << p1.second.second << " "      // 4
         << p1.second.first << endl;     // 3


    // Array of pairs
    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};

    // Accessing second element (index 1)
    cout << arr[1].first << " "          // 2
         << arr[1].second << endl;       // 5
}

int main(){
    explainPair();
    return 0;
}