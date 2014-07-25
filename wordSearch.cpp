#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        isFound = false;
        if(word == "") return false;
        pattern = word;
        this->height = board.size();
        if(height == 0) return false;
        this->width = board[0].size();
        if(width == 0) return false;
        table = board;
        vector<pair<int, int>> position;

        char firstChr = word[0];
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                cout << table[i][j] << " ";
                if(board[i][j] == firstChr)
                    position.push_back(make_pair(i, j));
            }
            cout << endl;
        }
        int index = 1;
        for(vector<pair<int, int>> :: iterator it = position.begin(); it != position.end(); ++it) {
            cout << "begin with :" << it->first << "" << it->second << " " << table[it->first][it->second] << endl;
            if(checkPattern(*it, 1) == true )
                return true;
        }
        return false;
    }
    bool checkPattern(pair<int, int>pos, int index) {
        bool next[4];
        vector<pair<int, int>> posStack;
        next[0] = checkNext(pos, 0, index, posStack);
        next[1] = checkNext(pos, 1, index, posStack);
        next[2] = checkNext(pos, 2, index, posStack);
        next[3] = checkNext(pos, 3, index, posStack);
        return next[0] || next[1] || next[2] || next[3];
    }
    bool checkNext(pair<int, int> pos, int direction, int index, vector<pair<int, int>> &posStack) {
        if(isFound) return true;
        if(index >= pattern.size()) {
            isFound = true;
            return true;
        }
        pos.first += dir[direction].y;
        pos.second += dir[direction].x;
        for(vector<pair<int, int>> :: iterator it = posStack.begin(); it != posStack.end(); ++it) {
            if(it->second == pos.second && it->first == pos.first) {
                return false;
            }
        }
        cout << "(" << pos.first << "," << pos.second << "), index is " << index << endl;
        if(pos.first < 0 || pos.first >= this->height) {
            return false; 
        }
        if(pos.second < 0 || pos.second >= this->width) {
            return false;
        }
        if(table[pos.first][pos.second] == pattern[index]) {
            posStack.push_back(pos);
            cout << "pattern matched : " << pattern[index] << endl;
            bool next[4];
            next[0] = checkNext(pos, 0, index + 1, posStack);
            next[1] = checkNext(pos, 1, index + 1, posStack);
            next[2] = checkNext(pos, 2, index + 1, posStack);
            next[3] = checkNext(pos, 3, index + 1, posStack);
            posStack.pop_back();
            if(next[0] || next[1] || next[2] || next[3])
                return true;
        }
        return false;
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
    vector<vector<char>> table;
    string pattern;
    bool isFound;
};


int main() {
    vector<vector<char>> vec = {{'a', 'b', 'c', 'e'}, {'s', 'f', 'c', 's'}, {'a', 'd', 'e', 'e'}};
    Solution sol;
    cout << sol.exist(vec, "see") << endl;
    return 0;
}
