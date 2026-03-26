// RAT IN A MAZE PROBLEM -> Backtracking approach

//Time Complexity: O(4^(n²)) in worst case (exponential due to backtracking)
//Space Complexity: O(n²) (visited matrix + recursion stack)

#include<bits/stdc++.h>
using namespace std;

// Function to check whether moving to (x, y) is safe or not
bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>> &m){
    // Conditions:
    // 1. x and y should be inside the grid
    // 2. Cell should not be visited already
    // 3. Cell should not be blocked (i.e., value should be 1)
    if((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1){
        return true;
    }
    return false;
}

// Recursive function to find all paths from (x, y) to destination
void solve(vector<vector<int>>& m, int n, vector<string> &ans, int x, int y, 
        vector<vector<int>>& visited, string path) {
        
        // Base case: if destination is reached, store the path
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }

        // Mark current cell as visited
        visited[x][y] = 1;

        // 4 possible moves: Down, Left, Right, Up

        // Move Down
        int newx = x+1;
        int newy = y;
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('D');                  // add move to path
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();                      // backtrack (remove last move)
        }

        // Move Left
        newx = x;
        newy = y-1;
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('L');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // Move Right
        newx = x;
        newy = y+1;
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('R');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // Move Up
        newx = x-1;
        newy = y;
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('U');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // Backtrack: unmark current cell so it can be used in other paths
        visited[x][y] = 0;
}

int main() {

    int n;
    cout << "enter the size of the matrix that is n : ";
    cin >> n;

    // Input the maze (0 = blocked, 1 = open path)
    vector<vector<int>> arr(n, vector<int>(n));
    cout << "enter the matrix elements(0&1) : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
        cout << endl;
    }

    // Store all possible paths
    vector<string> ans;

    // If starting cell is blocked, no path exists
    if(arr[0][0] == 0){
        cout << "no paths available!" << endl;
         return 0;
    }

    // Visited matrix to keep track of visited cells
    vector<vector<int>> visited(n, vector<int>(n, 0));
    
    // Path string to store directions
    string path = "";

    // Start recursion from (0,0)
    solve(arr, n, ans, 0, 0, visited, path);

    // Sort paths lexicographically (required in many problems like GFG)
    sort(ans.begin(), ans.end());

    // Print all possible paths
    cout << "\nPossible paths are:\n";
    for(auto &p : ans) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}