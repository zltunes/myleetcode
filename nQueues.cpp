#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<bool> bRow(10, false);
        vector<vector<bool>> bMap(10, bRow);
        vector<vector<string>> ret;
        stack<pair<int, int>> oprStack;
        stack<vector<pair<int, int>>> influStack;
        for(int i = 0; i < n; ++i) {
            pair<int, int> pos = make_pair(0, i);
            oprStack.push(pos);
            vector<pair<int, int>> influ = getInfluPos(pos, bMap);
            influStack.push(influ);
            for
        
        }

        return ret;
    }

    vector<pair<int, int>> getInfluPos(pair<int, int> & pos, vector<vector<bool>>& bMap) {
        vector<pair<int, int>> ret;
        int &row = pos.first;
        int &col = pos.second;
        for(int i = 0; i < bMap.size(); ++i) {
            if(!bMap[row][i]) {
                bMap[row][i] = true;
                ret.push_back(make_pair(row, i));
            }
            if(!bMap[i][col]) {
                bMap[i][col] = true;
                ret.push_back(make_pair(i, col));
            }
        }
        for(int i = row, j = col; i < bMap.size() && j < bMap.size(); ++i, ++j) {
            if(!bMap[i][j]) {
                bMap[i][j] = true;
                ret.push_back(make_pair(i, j));
            }
        }
        for(int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if(!bMap[i][j]) {
                bMap[i][j] = true;
                ret.push_back(make_pair(i, j));
            }
        }
        for(int i = row, j = col; i < bMap.size() && j >= 0; ++i, --j) {
            if(!bMap[i][j]) {
                bMap[i][j] = true;
                ret.push_back(make_pair(i, j));
            }
        }
        for(int i = row, j = col; i >= 0 && j < bMap.size(); --i, ++j) {
            if(!bMap[i][j]) {
                bMap[i][j] = true;
                ret.push_back(make_pair(i, j));
            }
        }
    }
};

int main() {

    return 0;
}
