// SET EXPLANATION
#include<bits/stdc++.h>
using namespace std;

void explainSet(){

    set<int> st;

    // Insert elements (stored sorted & unique)
    st.insert(5);
    st.insert(1);
    st.insert(3);
    st.insert(1);   // Duplicate ignored

    cout << "Set elements: ";
    for(auto it : st){
        cout << it << " ";
    }
    cout << endl;

    cout << "Size: " << st.size() << endl;

    // Find element
    if(st.find(3) != st.end()){
        cout << "3 is present\n";
    }

    // Erase single element
    st.erase(3);

    cout << "After erase: ";
    for(auto it : st){
        cout << it << " ";
    }
    cout << endl;

    // Lower bound → first element >= 2
    auto lb = st.lower_bound(2);

    if(lb != st.end())
        cout << "Lower bound of 2: " << *lb << endl;
    else
        cout << "Lower bound not found\n";

    // Upper bound → first element > 2
    auto ub = st.upper_bound(2);

    if(ub != st.end())
        cout << "Upper bound of 2: " << *ub << endl;
    else
        cout << "Upper bound not found\n";

    // Erase range [first, last)
    // safer example using lower_bound
    auto it1 = st.lower_bound(1);
    auto it2 = st.lower_bound(5);

    st.erase(it1, it2);   // removes elements in range

    cout << "After range erase: ";
    for(auto it : st){
        cout << it << " ";
    }
    cout << endl;
}

int main(){
    explainSet();
    return 0;
}