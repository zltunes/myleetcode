#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size() == 0) return 0;
        int height = triangle.size();
        for(int step = height - 1; step >= 0; --step) {
            for(int i = 0; i < step ; ++i) {
                triangle[step - 1][i] += min(triangle[step][i], triangle[step][i + 1]);
            }
        }
        return triangle[0][0];
    }

};

int main() {
    //vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    vector<vector<int>> triangle = {{2}};
    Solution sol;
    cout << sol.minimumTotal(triangle);

    return 0;
}
