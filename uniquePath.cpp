#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row(n, 1);
        vector<vector<int>> table(m, row);
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                table[i][j] = table[i - 1][j] + table[i][j - 1];
            } 
        }
        return table[m - 1][n - 1];
    }
};

int main() {
    Solution sol;
    cout << sol.uniquePaths(1,1) << endl;

    return 0;
}
