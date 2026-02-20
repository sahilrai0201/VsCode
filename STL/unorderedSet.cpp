// UNORDERED_SET EXPLANATION
#include<bits/stdc++.h>
using namespace std;

void explainUnorderedSet(){

    unordered_set<int> us;

    // Insert elements (duplicates ignored)
    us.insert(5);
    us.insert(1);
    us.insert(3);
    us.insert(1);   // duplicate ignored

    cout << "Unordered set elements: ";
    for(auto it : us){
        cout << it << " ";   // Order NOT guaranteed
    }
    cout << endl;

    // Size (unique elements only)
    cout << "Size: " << us.size() << endl;

    // Find element
    if(us.find(3) != us.end()){
        cout << "3 is present\n";
    }

    // Erase element
    us.erase(3);

    cout << "After erase: ";
    for(auto it : us){
        cout << it << " ";
    }
    cout << endl;

    // Count (returns 0 or 1)
    cout << "Count of 5: " << us.count(5) << endl;
}

int main(){
    explainUnorderedSet();
    return 0;
}