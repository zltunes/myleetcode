#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> vc;
typedef vector<vector<char> > vvc;
typedef vector<string> vs;

class Solution {
    typedef vector<vector<char> > vvc;
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        return checkCol(board) && checkRow(board) && checkGrid(board);
    }

    bool checkCol(vvc & board) {
        for(int i = 0; i < 9; ++i) {
            bool check[10] = { false };
            for(int j = 0; j < 9; ++j) {
                if(board[j][i] == '.') continue;
                if(check[board[j][i] - '0']) return false;
                check[board[j][i] - '0'] = true;
            }
        }
        return true;
    }
    bool checkRow(vvc & board) {
        for(auto & row : board) {
            bool check[10] = { false };
            for(auto & item : row) {
                if(item == '.') continue;
                if(check[item - '0']) return false;
                check[item - '0'] = true;
            }
        }
        return true;
    }
    bool checkGrid(vvc & board) {
        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                if(checkInnerGrid(board, i, j) == false)
                    return false;
            }
        }
        return true;
    }
    bool checkInnerGrid(vvc & board, int left, int top) {
        bool check[10] = { false };
        for(int i = left; i < left + 3; ++i) {
            for(int j = top; j < top + 3; ++j) {
                if(board[i][j] == '.') continue;
                if(check[board[i][j] - '0']) return false;
                check[board[i][j] - '0'] = true;
            }
        }
        return true;
    }
};

void printVVC(vvc & board) {
    for(auto & row : board) {
        for(auto & chr : row) {
            cout << chr;
        }
        cout << endl;
    }
}

void printVS(vs & board) {
    for(auto & row : board) {
        for(auto & chr : row) {
            cout << chr;
        }
        cout << endl;
    }
}

vvc construct(const vs & board) {
    vvc ret;
    vc temp;
    for(auto & row : board) {
        ret.push_back(temp);
        for(auto &chr : row) {
            ret.back().push_back(chr);
        }
        temp.clear();
    }
    return ret;
}

int main() {
    vs temp {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};
    vvc board = construct(temp);
    printVVC(board);
    Solution sol;
    cout << sol.isValidSudoku(board) << endl;
    return 0;
}
