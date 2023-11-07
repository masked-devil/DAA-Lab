#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(i - row) == abs(board[i] - col)) {
            return false;
        }
    }
    return true;
}

void printBoard(vector<int>& board) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                cout << "Q" << i + 1 << " ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
    }
}

bool solveNQueensUtil(vector<int>& board, int row) {
    int n = board.size();
    if (row == n) {
        printBoard(board);
        cout << endl;
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, row, i)) {
            board[row] = i;
            res = solveNQueensUtil(board, row + 1) || res;
            board[row] = -1; // Backtrack
        }
    }

    return res;
}

void solveNQueens(int n) {
    vector<int> board(n, -1);
    if (!solveNQueensUtil(board, 0)) {
        cout << "Solution does not exist." << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    solveNQueens(n);

    return 0;
}
