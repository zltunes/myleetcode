#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

vvc transform(const vvi &vec) {
    vvc ret;
    int height = vec.size();
    if(height == 0) return ret;
    int width = vec[0].size();
    if(width == 0) return ret;

    vc t;
    t.resize(width, 0);
    ret.resize(height, t);

    for(int i = 0; i < height; ++i)
        for(int j = 0; j < width; ++j)
            ret[i][j] = static_cast<char>(vec[i][j] + '0');

    return ret;
}

class Solution {
    using vi = vector<int>;
    using vvi = vector<vi>;
    using vc = vector<char>;
    using vvc = vector<vc>;
public:
    int largestRect(vi &histogram) {
        vi stk;
        histogram.push_back(0);
        int size = histogram.size();
        int max_rect = 0;

        int i = 0;
        while(i < size) {
            if(stk.empty() || histogram[stk.back()] <= histogram[i])
                stk.push_back(i++);
            else {
                int t = histogram[stk.back()]; stk.pop_back();
                int l = stk.empty() ? i : i - stk.back() - 1; 
                max_rect = max(max_rect, l * t); 
            }
        }

        return max_rect;
    }

    int maximalRectangle(vector<vector<char> > &matrix) {
        int height = matrix.size();
        if(height == 0) return 0;
        int width = matrix[0].size();
        if(width == 0) return 0;

        vi t;
        t.resize(width, 0);
        vvi dp;
        dp.resize(height, t);

        for(int i = 0; i < width; ++i)
            dp[0][i] = matrix[0][i] == '1' ? 1 : 0;

        for(int i = 0; i < width; ++i)
            for(int j = 1; j < height; ++j)
                dp[j][i] = matrix[j][i] == '1' ? dp[j - 1][i] + 1 : 0;

        /*for(auto &row : dp) {
            for(auto &item : row)
                cout << item << ' ';
            cout << endl; 
        }*/

        int max_rect = 0;
        for(auto &row : dp) {
            int area = largestRect(row);
            max_rect = max(max_rect, area);
        }

        return max_rect;
    }
};

int main() {
    vvi matrix {
        {0,1,1},
    };

    for(auto &row : matrix) {
        for(auto &item : row)
            cout << item << ' ';
        cout << endl;
    }

    vvc test = transform(matrix);
    Solution sol;
    cout << sol.maximalRectangle(test) << endl;
    return 0;
}
