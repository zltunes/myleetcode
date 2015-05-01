#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > vvi;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int lenY = matrix.size();
        if(lenY == 0) return false;
        int lenX = matrix[0].size();
        if(lenX == 0) return false;
        int size = lenX * lenY; 
        int i = 0, j = size - 1;
        while(i <= j) {
            int mid = (i + j) / 2;
            int mid_x = mid % lenX;
            int mid_y = mid / lenX;
            if(matrix[mid_y][mid_x] == target) return true;
            if(matrix[mid_y][mid_x] < target) {
                i = mid + 1;
            }
            if(matrix[mid_y][mid_x] > target) {
                j = mid - 1;
            }
        }
        return false;
    }
};


int main() {
    vvi vec = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,50}
    };

    int target = 24;
    Solution sol;
    cout << sol.searchMatrix(vec, target) << endl;
    return 0;
}
