#include <iostream>
#include <vector>
using namespace std;

class Solution {
    typedef vector<int> vi;
    typedef vector<vi> vvi;
public:
    vector<vector<int> > generateMatrix(int n) {
        vvi ret;
        vi row;
        row.resize(n, -1);
        ret.resize(n, row);
        int cnt = 1;
        int level = 0;
        while(level < (n + 1) / 2) {
            for(int i = level; i < n - 1 - level; ++i) {
                ret[level][i] = cnt;
                ++cnt;
            }
            for(int i = level; i < n - 1 - level; ++i) {
                ret[i][n - 1 - level] = cnt;
                ++cnt;
            }
            for(int i = level; i < n - 1 - level; ++i) {
                ret[n - 1 - level][n - 1 - i] = cnt;
                ++cnt;
            }
            for(int i = level; i < n - 1 - level; ++i) {
                ret[n - 1 - i][level] = cnt;
                ++cnt;
            }
            ++level;
        }
        if(n & 1) {
            ret[n / 2][n / 2] = cnt;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    sol.generateMatrix(1);

    return 0;
}
