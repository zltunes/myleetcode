#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int height = grid.size();
        if(height == 0) return 0;
        int width = grid[0].size();
        if(width == 0) return 0;
        for(int i = 1; i < width; ++i)
            grid[0][i] = grid[0][i - 1] + grid[0][i];
        for(int i = 1; i < height; ++i)
            grid[i][0] = grid[i - 1][0] + grid[i][0];
        for(int i = 1; i < height; ++i) {
            for(int j = 1; j < width; ++j) {
                grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
        return grid[height - 1][width - 1];
    }
};


int main() {
    vector<vector<int> > vec = {{1,2,5},{3,2,1}};
    Solution sol;
    cout << sol.minPathSum(vec);
    return 0;
}
