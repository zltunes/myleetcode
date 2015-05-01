#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printBoard(vector<vector<char> > &board) {
    for(auto row : board) {
        for(auto chr : row)
            cout << chr;
        cout << endl;
    }
    cout << endl;
}

class Solution {
public:
    bool isValid(vector<vector<char> > &board, int nRow, int nCol) {
        char number = board[nRow][nCol];
        for(int i = 0; i < 9; ++i)
            if(board[nRow][i] == number && nCol != i)
                return false;
        for(int i = 0; i < 9; ++i)
            if(board[i][nCol] == number && nRow != i)
                return false;
        int horizontal = nCol / 3;
        int vertical = nRow / 3;
        for(int i = vertical * 3; i < (vertical + 1) * 3; ++i)
            for(int j = horizontal * 3; j < (horizontal + 1) * 3; ++j)
                if(board[i][j] == number && (i != nRow || j != nCol))
                    return false;        
        return true;
    }

    bool solveSudokuWorker(vector<vector<char> >& board) {
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') continue;
                for(int n = 1; n <= 9; ++n) {
                    board[i][j] = '0' + n;
                    if(isValid(board, i, j)) {
                     //   printBoard(board);
                        if(solveSudokuWorker(board)) {
                            return true;
                        }
                    }
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char> > &board) {
        solveSudokuWorker(board);
    }
};

int main() {
    vector<string> store = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    vector<vector<char> > board;
    vector<char> t;
    for(auto s : store) {
        for(auto chr : s) {
            t.push_back(chr);
        }
        board.push_back(t);
        t.clear();
    }
    printBoard(board);
    Solution sol;
    sol.solveSudoku(board);
    printBoard(board);
    return 0;
}
