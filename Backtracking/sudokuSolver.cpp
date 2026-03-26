#include <bits/stdc++.h>
using namespace std;

// Function to check if placing 'val' at board[row][col] is valid
bool isSafe(int row, int col, vector<vector<char>> &board, char val){
    for(int i=0;i<9;i++){
        // Check the row for the same value
        if(board[row][i] == val) return false;

        // Check the column for the same value
        if(board[i][col] == val) return false;

        // Check the 3x3 subgrid for the same value
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val) return false;
    }
    return true; // Safe to place 'val' at board[row][col]
}

// Recursive function to solve the Sudoku using backtracking
bool solve(vector<vector<char>> &board){
    int n = board.size(); // Size of the board (9x9)

    // Traverse each cell in the board
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            // If the cell is empty (represented by '0')
            if(board[row][col] == '0'){
                // Try placing digits '1' to '9' in the empty cell
                for(char val='1'; val<='9'; val++){
                    // Check if it's safe to place 'val'
                    if(isSafe(row, col, board, val)){
                        board[row][col] = val; // Place the value

                        // Recursively solve for the next cells
                        if(solve(board)) return true;

                        // Backtrack: undo the placement if it leads to no solution
                        board[row][col] = '0';
                    }
                }
                return false; // If no value can be placed, return false
            }
        }
    }
    return true; // All cells filled successfully
}

// Wrapper function to start the Sudoku solver
void solveSudoku(vector<vector<char>> &board){
    solve(board);
}

int main() {
    vector<vector<char>> board(9, vector<char>(9)); // 9x9 Sudoku board

    // Input the board from user
    cout << "Enter the Sudoku board (use 0 for empty cells):\n";
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> board[i][j]; // Read each cell
        }
    }

    // Solve the Sudoku and display the solution
    if(solveSudoku(board), true){ // The comma operator always returns true here
        cout << "\nSolved Sudoku:\n";
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << board[i][j] << " "; // Print each row
            }
            cout << "\n";
        }
    } 
    else {
        cout << "No solution exists for the given Sudoku.\n"; // No solution found
    }

    return 0; 
}


//sudoku input ->
// 530070000
// 600195000
// 098000060
// 800060003
// 400803001
// 700020006
// 060000280
// 000419005
// 000080079