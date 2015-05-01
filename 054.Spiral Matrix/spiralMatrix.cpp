#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> &vec);
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        if(matrix.size() == 0) return ret;
        int height = matrix.size();
        if(matrix[0].size() == 0) return ret;
        int width = matrix[0].size();
        int top = 0;
        int botton = height - 1;
        int left = 0;
        int right = width - 1;
        while(true) {
            for(int pos = left; pos <=right; ++pos)
                ret.push_back(matrix[top][pos]);
            top++;
            for(int pos = top; pos <= botton; ++pos)
                ret.push_back(matrix[pos][right]);
            right--;
            if(left > right || top > botton) break;
            for(int pos = right; pos >= left; --pos)
                ret.push_back(matrix[botton][pos]);
            botton--;
            for(int pos = botton; pos >= top; --pos)
                ret.push_back(matrix[pos][left]);
            left++;
            if(left > right || top > botton) break;
        }
        return ret;
    }
};

void printVec(vector<int> vec) {
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> vec = {{3},{2}};
    Solution sol;
    printVec(sol.spiralOrder(vec));

    return 0;
}
