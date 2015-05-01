#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > vvi;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.size() == 0) return 0;
        if(obstacleGrid[0].size() == 0) return 0;
        if(obstacleGrid[0][0] == 1) return 0;
        int dp[100][100];
        dp[0][0] = 1;
        int lenY = obstacleGrid.size();
        int lenX = obstacleGrid[0].size();
        cout << lenX << ' ' << lenY << endl;
        for(int i = 1; i < lenX; ++i) {
            if(obstacleGrid[0][i]) dp[0][i] = 0;
            else {
                dp[0][i] = dp[0][i - 1];
            }
        }
        for(int j = 1; j < lenY; ++j) {
            if(obstacleGrid[j][0]) dp[j][0] = 0;
            else {
                dp[j][0] = dp[j - 1][0];
            }
        }
        for(int i = 1; i < lenY; ++i) {
            for(int j = 1; j < lenX; ++j) {
                if(obstacleGrid[i][j]) dp[i][j] = 0;
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[lenY - 1][lenX - 1];
    }
};

int main() {
    vvi map = {
        {0,1,0,0,0},
        {1,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
    };

    Solution sol;
    cout << sol.uniquePathsWithObstacles(map) << endl;
    return 0;
}
