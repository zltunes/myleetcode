#include <iostream>
#include <vector>
#include <deque>
using namespace std;

using vc = vector<char>;
using vvc = vector<vc>;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int cnt = 0;
        deque<pair<int, int>> q;
        int height = grid.size();
        if(height == 0) return cnt;
        int width = grid[0].size();
        if(width == 0)  return cnt;
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                if(grid[i][j] != '1') continue;
                q.clear();
                q.push_back(make_pair(i, j));
                while(!q.empty()) {
                    int curX = q.front().first;
                    int curY = q.front().second;
                    if(curX > 0 && grid[curX - 1][curY] == '1') {
                        q.push_back(make_pair(curX - 1, curY));
                        grid[curX - 1][curY] = '0';
                    }
                    if(curX < height - 1 && grid[curX + 1][curY] == '1') {
                        q.push_back(make_pair(curX + 1, curY));
                        grid[curX + 1][curY] = '0';
                    }
                    if(curY > 0 && grid[curX][curY - 1] == '1') {
                        q.push_back(make_pair(curX, curY - 1));
                        grid[curX][curY - 1] = '0';
                    }
                    if(curY < width - 1 && grid[curX][curY + 1] == '1') {
                        q.push_back(make_pair(curX, curY + 1));
                        grid[curX][curY + 1] = '0';
                    }
                    q.pop_front(); 
                }
                ++cnt;
            }
        }
        return cnt;
    }
};

int main() {

    vvc grid {
        {'1','1','0','0','0'},
        {'1','1','0','1','0'},
        {'0','0','0','0','0'},
        {'0','0','0','1','1'},
    };

    Solution sol;

    cout << sol.numIslands(grid) << endl;
    return 0;
}
