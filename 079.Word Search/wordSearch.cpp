#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> vc;
typedef vector<vc>   vvc;

class Solution {
    typedef vector<char> vc;
    typedef vector<vc>   vvc;
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word.size() == 0) return false;
        char head = word.front();
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                char temp = board[i][j];
                if(temp == head) {
                    board[i][j] = '.';
                    if(check(board, i, j, word.substr(1, word.size() - 1)))
                        return true;
                    board[i][j] = temp;
                }
            }
        }
        return false;
    }

    bool check(vvc &board, int i, int j, string word) {
        if(word.size() == 0) return true;
        char &head = word.front();
        int len_y = board.size();
        int len_x = board[0].size();
        if(i + 1 < len_y && board[i + 1][j] == head) {
            char temp = board[i + 1][j];
            board[i + 1][j] = '.';
            if(check(board, i + 1, j, word.substr(1, word.size() - 1)))
                return true;
            board[i + 1][j] = temp;
        }
        if(i - 1 >= 0 && board[i - 1][j] == head) {
            char temp = board[i - 1][j];
            board[i - 1][j] = '.';
            if(check(board, i - 1, j, word.substr(1, word.size() - 1)))
                return true;
            board[i - 1][j] = temp;
        }
        if(j + 1 < len_x && board[i][j + 1] == head) {
            char temp = board[i][j + 1];
            board[i][j + 1] = '.';
            if(check(board, i, j + 1, word.substr(1, word.size() - 1)))
                return true;
            board[i][j + 1] = temp;
        }
        if(j - 1 >= 0 && board[i][j - 1] == head) {
            char temp = board[i][j - 1];
            board[i][j - 1] = '.';
            if(check(board, i, j - 1, word.substr(1, word.size() - 1)))
                return true;
            board[i][j - 1] = temp;
        }
        return false;
    }
};


int main() {
    vvc vec = {
        {'a', 'b', 'c', 'e'}, 
        {'s', 'f', 'c', 's'}, 
        {'a', 'd', 'e', 'e'}
    };

    Solution sol;
    cout << sol.exist(vec, "abcce") << endl;
    return 0;
}
