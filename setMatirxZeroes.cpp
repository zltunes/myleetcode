#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

void printVec(vector<vector<int>> &vec) {
    for(auto row : vec) {
        for(auto item : row)
            cout << item << " ";
        cout << endl;
    }
}
class Solution {
public:
    typedef unordered_map<int, vector<int>> MAP;
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.size() == 0) return;
        int height = matrix.size();
        if(matrix[0].size() == 0) return;
        int width = matrix[0].size();
        MAP recorder;
        set<int> recorderColumn;

        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                if(matrix[i][j] == 0) {
                    recorder[i].push_back(j);
                }
            }
        }

        for(auto kv : recorder) {
            setZeroWidth(kv.first, matrix);
            vector<int> & vec = kv.second;
            for(auto item : vec)
                recorderColumn.insert(item);
        }
        for(auto item : recorderColumn)
            setZeroHeight(item, matrix);
    }
    typedef vector<vector<int>> mat;
    void setZeroWidth(int height, mat &matrix) {
        fill(matrix[height].begin(), matrix[height].end(), 0);
    }

    void setZeroHeight(int width, mat &matrix) {
        for(int i = 0; i < matrix.size(); ++i) {
            matrix[i][width] = 0;
        }
    }

};

int main() {
    Solution sol;
    vector<vector<int>> vec = {{0,1,0},{2,3,4},{2,4,7}};
    printVec(vec);
    sol.setZeroes(vec);
    printVec(vec);
    return 0;
}
