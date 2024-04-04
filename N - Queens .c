#include <iostream>
#include <vector>

using namespace std;

// A utility function to print solution
void printSolution(const vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
}


bool isSafe(const vector<vector<int>>& board, int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; ++i)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < board.size(); ++i, --j)
        if (board[i][j])
            return false;

    return true;
}

// A recursive utility function to solve N
bool solveNQUtil(vector<vector<int>>& board, int col) {

    if (col >= board.size())
        return true;


    for (int i = 0; i < board.size(); ++i) {

        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // recur to place rest of the queens
            if (solveNQUtil(board, col + 1))
                return true;

     
            board[i][col] = 0; // BACKTRACK
        }
    }

    // If the queen cannot be placed in any row in
    // this column col then return false
    return false;
}


bool solveNQ(int n) {
    if (n <= 0) {
        cout << "Invalid board size.\n";
        return false;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!solveNQUtil(board, 0)) {
        cout << "Solution does not exist\n";
        return false;
    }

    printSolution(board);
    return true;
}

// Driver program to test above function
int main() {
    int n;
    cout << "Enter the size of the board: ";
    cin >> n;
    solveNQ(n);
    return 0;
}
