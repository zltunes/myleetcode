#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n == 0) return 0;
        int l = 0, r = n - 1; 
        while(l <= r) {
            int mid = (l + r) / 2;
            if(A[mid] == target) return mid;
            else if(A[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return l;
    }
};

int main() {
    int A[] = {1,3,5,6};
    int target = 0;
    const int SIZE_INT = sizeof(int);

    Solution sol;
    cout << sol.searchInsert(A, sizeof(A) / SIZE_INT, target) << endl;

    return 0;
}
