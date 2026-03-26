#include<bits/stdc++.h>
using namespace std;

// Convert the current board state to a solution and add it to ans
void addSolution(vector<vector<string>> &ans, vector<vector<int>> &board, int n){
    vector<string> temp; // temporary vector to store one solution

    for(int i=0; i<n; i++){           // loop through each row
        string row = "";               // string to store the row
        for(int j=0; j<n; j++){       // loop through each column
            if(board[i][j] == 1){     // if queen is present
                row.push_back('Q');
            }
            else{                      // empty cell
                row.push_back('.');
            }
        }
        temp.push_back(row);          // add the row to current solution
    }
    ans.push_back(temp);              // add the complete solution to answer list
}

// Check if placing a queen at (row, col) is safe
bool isSafe(int row, int col, vector<vector<int>> &board, int n){
    int x, y;

    // check left in the same row
    x = row; y = col;
    while(x >= 0 && y >= 0){
        if(board[x][y] == 1) return false;
        y--;
    }

    // check upper-left diagonal
    x = row; y = col;
    while(x >= 0 && y >= 0){
        if(board[x][y] == 1) return false;
        x--; y--;
    }

    // check lower-left diagonal
    x = row; y = col;
    while(x < n && y >= 0){
        if(board[x][y] == 1) return false;
        x++; y--;
    }

    return true; // safe to place
}

// Recursive function to place queens column by column
void solve(int col, vector<vector<string>> &ans, vector<vector<int>> &board, int n){
    // Base case: all columns filled
    if(col == n){
        addSolution(ans, board, n);
        return;
    }

    // Try placing a queen in all rows of this column
    for(int row=0; row<n; row++){
        if(isSafe(row, col, board, n)){ // if safe
            board[row][col] = 1;        // place queen
            solve(col+1, ans, board, n); // recurse for next column
            board[row][col] = 0;        // backtrack
        }
    }
}

// Initialize board and start solving
vector<vector<string>> solveNQueens(int n){
    vector<vector<int>> board(n, vector<int>(n, 0)); // n x n board
    vector<vector<string>> ans;                        // store all solutions
    solve(0, ans, board, n);                           // start from column 0
    return ans;                                        // return solutions
}

// Main function to read input and display solutions
int main(){
    int n;
    cout << "Enter the size of square matrix : " << endl;
    cin >> n;

    vector<vector<string>> result = solveNQueens(n); // solve N-Queens

    cout << "Total solution : " << result.size() << endl << endl;

    // Print each solution
    for(int k=0; k<(int)result.size(); k++){
        cout << "Solution " << k+1 << ":" << endl;
        for(int i=0; i<n; i++){
            cout << result[k][i] << endl; // print row
        }
        cout << endl; //extra line for separate solutions
    }

    return 0;
}