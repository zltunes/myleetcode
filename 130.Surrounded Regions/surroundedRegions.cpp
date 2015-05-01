#include <iostream>
#include <vector>
#include <deque>
using namespace std;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;
using vpii = vector<pii>;

class Solution {
    using vc = vector<char>;
    using vvc = vector<vc>;
    using pii = pair<int, int>;
    using vpii = vector<pii>;
public:
    void solve(vector<vector<char>> &board) {
        if(board.size() == 0) return;
        int height = board.size();
        if(board[0].size() == 0) return;
        int width = board[0].size();

        vpii zeros;
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                if(board[i][j] == 'O') {
                    if(i == 0 || j == 0 || i == height - 1 || j == width - 1) {
                        zeros.push_back(make_pair(i, j));   
                    }
                    board[i][j] = '.';
                }
            }
        }

        for(auto &pos : zeros) {
            deque<pair<int, int>> temp {pos};
            while(!temp.empty()) {
                pair<int, int> t = temp.front();
                if(board[t.first][t.second] == '.') {
                    if(t.first < height - 1 && board[t.first + 1][t.second] == '.')
                        temp.push_back(make_pair(t.first + 1, t.second));
                    if(t.first > 0 && board[t.first - 1][t.second] == '.')
                        temp.push_back(make_pair(t.first - 1, t.second));
                    if(t.second < width - 1 && board[t.first][t.second + 1] == '.')
                        temp.push_back(make_pair(t.first, t.second + 1));
                    if(t.second > 0 && board[t.first][t.second - 1] == '.')
                        temp.push_back(make_pair(t.first, t.second - 1));
                    board[t.first][t.second] = 'O';
                }
                temp.pop_front();
            }
        }
        for(auto &row : board)
            for(auto &item : row)
                if(item == '.') item = 'X';
    }
};

int main() {

    vvc test = {
        {'X','X','O','X'},
        {'X','O','X','X'},
        {'O','X','O','X'},
        {'X','O','X','O'},
        {'X','X','X','O'},
        {'X','O','X','O'}
    };
    Solution sol;
    sol.solve(test);

    for(auto &row : test) {
        for(auto &item : row)
            cout << item;
        cout << endl;
    }
    return 0;
}
