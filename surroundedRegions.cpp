#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.size() == 0) return;
        this->height = board.size();
        if(board[0].size() == 0) return;
        this->width = board[0].size();

        vector<pair<int, int>> circleVec;
        for(int i = 1; i < height - 1; ++i) {
            if(board[0][i] == 'O') circleVec.push_back(make_pair(0,i));
            if(board[i][0] == 'O') circleVec.push_back(make_pair(i,0));
            if(board[height - 1][i] == 'O') circleVec.push_back(make_pair(height - 1,i));
            if(board[i][width - 1] == 'O') circleVec.push_back(make_pair(i,width - 1));
        }
        solution2(circleVec, board);
    }

    void solution2(vector<pair<int, int>> &circleVec, vector<vector<char>> &board) {
        deque<pair<int, int>> queue;
        for(auto item : circleVec) {
            queue.push_back(item);
            while(!queue.empty()) {
                pair<int, int> & t = queue.front();
                queue.pop_front();
                circlePos.push_back(t);
                board[t.first][t.second] = 'X';
                pair<int, int> dirs[4];
                dirs[0] = make_pair(t.first, t.second + 1);
                dirs[1] = make_pair(t.first + 1, t.second);
                dirs[2] = make_pair(t.first, t.second - 1);
                dirs[3] = make_pair(t.first - 1, t.second);
                for(auto dir : dirs) {
                    if(isCircleBlock(dir, board))
                        queue.push_back(dir);
                }
            }
        }
        for(int i = 0; i < height; ++i)
            for(int j = 0; j < width; ++j)
                board[i][j] = 'X';
        for(auto item : circlePos) {
            board[item.first][item.second] = 'O';
        }
    }



    bool isCircleBlock(pair<int, int> &block, vector<vector<char>> &board) {
        if(block.first < 0 || block.first > height - 1) return false;
        if(block.second < 0 || block.second > width - 1) return false;
        if(board[block.first][block.second] == 'X') return false;
        return true;
    }

    void solution1(vector<pair<int, int>> &circleVec, vector<vector<char>> &board) {
        for(auto item : circleVec) {
            findNextCircleBlock(item, board);
        }
        for(int i = 0; i < height; ++i)
            for(int j = 0; j < width; ++j)
                board[i][j] = 'X';
        for(auto item : circlePos) {
            board[item.first][item.second] = 'O';
        }
    }

    void findNextCircleBlock(pair<int, int> pos, vector<vector<char>> &board) {
        if(pos.first < 0 || pos.first >= height) return;
        if(pos.second < 0 || pos.second >= width) return;
        if(board[pos.first][pos.second] == 'O') {
            board[pos.first][pos.second] = 'X';
            circlePos.push_back(pos);
        }
        else
            return;
        int &x = pos.first;
        int &y = pos.second;

        findNextCircleBlock(make_pair(x + 1, y), board);
        findNextCircleBlock(make_pair(x, y + 1), board);
        findNextCircleBlock(make_pair(x - 1, y), board);
        findNextCircleBlock(make_pair(x, y - 1), board);
    }
private:
    int height, width;
    vector<vector<char>> mBoard;
    vector<pair<int, int>> circlePos;
};

int main() {

    vector<vector<char>> mBoard = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    //vector<vector<char>> mBoard = {{'O','O','O'},{'O','O','O'},{'O','O','O'}};
    Solution sol;
    sol.solve(mBoard);

    for(int i = 0; i < mBoard.size(); ++i) {
        for(int j = 0; j < mBoard[0].size(); ++j)
            cout << mBoard[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
