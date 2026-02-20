// UNORDERED_MAP EXPLANATION
#include<bits/stdc++.h>
using namespace std;

void explainUnorderedMap(){

    unordered_map<int, string> um;

    // Insert elements (keys must be unique)
    um[1] = "Sahil";
    um[2] = "Rai";
    um[3] = "C++";
    um[2] = "Updated";   // updates value of key 2

    cout << "Unordered map elements:\n";
    for(auto it : um){
        cout << it.first << " -> " << it.second << endl;
        // Order NOT guaranteed
    }

    // Size (unique keys only)
    cout << "Size: " << um.size() << endl;

    // Find element
    if(um.find(3) != um.end()){
        cout << "Key 3 is present\n";
    }

    // Erase element
    um.erase(3);

    cout << "After erase:\n";
    for(auto it : um){
        cout << it.first << " -> " << it.second << endl;
    }

    // Count (returns 0 or 1)
    cout << "Count of key 1: " << um.count(1) << endl;
}

int main(){
    explainUnorderedMap();
    return 0;
}