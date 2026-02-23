#include<iostream>
using namespace std;

void solve(string str, string output, int index) {

    //base case
    if (index >= str.length()) {
        if(output.length()){
            cout << output << endl;
        }
        return;
    }

    //exclude
    solve(str, output, index+1);

    //include
    solve(str, output + str[index], index + 1);
}

int main() {

    string str = "abc";
    string output = "";
    int index = 0;

    solve(str, output, index);

    return 0;
}
