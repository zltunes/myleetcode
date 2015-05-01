#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printMat(vector<vector<int>> & mat) {
    for(auto row : mat) {
        for(auto item : row)
            cout << item;
        cout <<endl;
    }
    cout << endl;
}
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if(matrix.size() == 0) return;
        int size = matrix.size();
        int round = size / 2;
        int cnt = 0;
        while(cnt < round) {
            for(int i = cnt; i < size - cnt - 1; ++i) {
                int temp = matrix[i][cnt];
                matrix[i][cnt] = matrix[size - cnt - 1][i];
                matrix[size - cnt -1][i] = matrix[size - i - 1][size - cnt -1];
                matrix[size - i - 1][size - cnt - 1] = matrix[cnt][size - i - 1];
                matrix[cnt][size - i - 1] = temp;
            }
            ++cnt;
        }
    }
};

int main() {
    vector<vector<int> > mat = {{1}};
    printMat(mat);
    Solution sol;
    sol.rotate(mat);
    printMat(mat);
    return 0;
}
