#include<iostream>
#include<vector>
using namespace std;

void lettersComination (string digit, string output, int index, vector<string>& ans, string mapping[]) {

    //base case
    if(index >= digit.length()) {
        ans.push_back(output);
        return;
    }

    int number = digit[index] - '0';
    string value = mapping[number];

    for(int i = 0; i < value.length(); i++) {
        output.push_back(value[i]);
        lettersComination (digit, output, index + 1, ans, mapping);
        output.pop_back();
    }
    
}

int main() {
    string digits = "23";
    
    vector<string> ans;
    if(digits.length() == 0)  return 0;

    string output = "";
    int index = 0;
    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    lettersComination(digits, output, index, ans, mapping);

    for(auto s : ans) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
