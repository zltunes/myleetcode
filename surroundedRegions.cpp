#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.size() == 0) return;
        this->height = board.size();
        if(board[0].size() == 0) return;
        this->width = board[0].size();

        mBoard = board;
        vector<pair<int, int>> circleVec;
        for(int i = 1; i < height - 1; ++i) {
            if(board[0][i] == 'O') circleVec.push_back(make_pair(0,i));
            if(board[i][0] == 'O') circleVec.push_back(make_pair(i,0));
            if(board[height - 1][i] == 'O') circleVec.push_back(make_pair(height - 1,i));
            if(board[i][width - 1] == 'O') circleVec.push_back(make_pair(i,width - 1));
        }
        for(auto item : circleVec) {
            findNextCircleBlock(item);
        }
        for(int i = 0; i < height; ++i)
            for(int j = 0; j < width; ++j)
                board[i][j] = 'X';
        for(auto item : circlePos) {
            board[item.first][item.second] = 'O';
        }
    }

    void findNextCircleBlock(pair<int, int> pos) {
        if(pos.first < 0 || pos.first >= height) return;
        if(pos.second < 0 || pos.second >= width) return;
        if(mBoard[pos.first][pos.second] == 'O') {
            mBoard[pos.first][pos.second] = 'X';
            circlePos.push_back(pos);
        }
        else
            return;
        int &x = pos.first;
        int &y = pos.second;

        findNextCircleBlock(make_pair(x + 1, y));
        findNextCircleBlock(make_pair(x, y + 1));
        findNextCircleBlock(make_pair(x - 1, y));
        findNextCircleBlock(make_pair(x, y - 1));
    }
private:
    int height, width;
    vector<vector<char>> mBoard;
    vector<pair<int, int>> circlePos;
};

int main() {

    //vector<vector<char>> mBoard = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    vector<vector<char>> mBoard = {{'O','O','O'},{'O','O','O'},{'O','O','O'}};
    Solution sol;
    sol.solve(mBoard);

    for(int i = 0; i < mBoard.size(); ++i) {
        for(int j = 0; j < mBoard[0].size(); ++j)
            cout << mBoard[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
