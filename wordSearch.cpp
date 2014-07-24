#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word == "") return false;
        this->height = board.size();
        if(height == 0) return false;
        this->width = board[0].size();
        if(width == 0) return false;
        vector<pair<int, int>> position;

        char firstChr = word[0];
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                if(board[i][j] == firstChr) {
                    position.push_back(make_pair(i, j));
                } 
            }
        }

        int index = 1;
        while(index < word.length()) {
            word
        }
    }
    bool checkNext(pair<int, int> pos, int direction) {
        pos.first += dir[direction].y;
        pos.second += dir[direction].x;
        if(pos.first < 0 || pos.first >= this->height) {
            return false; 
        }
        if(pos.second < 0 || pos.second >= this->width) {
            return false;
        }

    }
    Solution() {
        dir[0].x = 1;
        dir[0].y = 0;
        dir[1].x = 0;
        dir[1].y = 1;
        dir[2].x = -1;
        dir[2].y = 0;
        dir[3].x = 0;
        dir[3].y = -1;
    }
private:
    struct Dir {
        int x, y;
    } dir[4];
    int height, width;
};


int main() {
    vector<vector<char>> vec;
    vector<char> inner_vec;
    inner_vec.push_back('1');
    vec.push_back(inner_vec);
    Solution sol;
    sol.exist(vec, "");
    return 0;
}
