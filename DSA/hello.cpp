#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>> &m){
    if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y] == 1){
        return true;
    }
    return false;
}

void solve(vector<vector<int>>& m, int n, vector<string> &ans, int x, int y, vector<vector<int>>& visited, string path) {

        //base case
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }

        //mark current cell as visited
        visited[x][y] = 1;

        //4-choices __ D,L,R,U

        //down
        int newx = x+1;
        int newy = y;
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('D');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        //left
        newx = x;
        newy = y-1;
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('L');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        //right
        newx = x;
        newy = y+1;
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('R');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        //up
        newx = x-1;
        newy = y;
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('U');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        //backtrack
        visited[x][y] = 0;
}

int main() {

    int n;
    cout << "enter the size of the matrix that is n : ";
    cin >> n;

    //give any array as input
    vector<vector<int>> arr(n, vector<int>(n));
    cout << "enter the matrix elements(0&1) : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
        cout << endl;
    }

    //code
    vector<string> ans;
    if(arr[0][0] == 0){
        cout << "no paths available!" << endl;
         return 0;
    }

    vector<vector<int>> visited(n, vector<int>(n, 0));
    
    string path = "";
    solve(arr, n, ans, 0, 0, visited, path);

    sort(ans.begin(), ans.end());

    cout << "\nPossible paths are:\n";
    for(auto &p : ans) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}