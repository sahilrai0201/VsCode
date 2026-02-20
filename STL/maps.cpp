// MAP EXPLANATION
#include<bits/stdc++.h>
using namespace std;

void explainMap(){

    map<int, string> m;

    // Insert elements (keys must be unique)
    m[1] = "Sahil";
    m[2] = "Rai";
    m[3] = "C++";
    m[2] = "Updated";   // updates value of key 2

    cout << "Map elements:\n";
    for(auto it : m){
        cout << it.first << " -> " << it.second << endl;
        // Keys are stored in SORTED order
    }

    // Size (unique keys only)
    cout << "Size: " << m.size() << endl;

    // Find element by key
    if(m.find(3) != m.end()){
        cout << "Key 3 is present\n";
    }

    // Erase element
    m.erase(3);

    cout << "After erase:\n";
    for(auto it : m){
        cout << it.first << " -> " << it.second << endl;
    }

    // Count (returns 0 or 1 since keys are unique)
    cout << "Count of key 1: " << m.count(1) << endl;
}

int main(){
    explainMap();
    return 0;
}