#include <iostream>
using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        int cnt;
        for(cnt = 0; cnt < n - 1; ++cnt)
            if(A[cnt] > A[cnt + 1])
                break;
        int offset = cnt + 1;

        int left, right;
        left = 0, right = n - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            int _mid = change(mid, offset, n);
            if(A[_mid] == target) return true;
            else if(A[_mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }

    int change(int pos, int offset, int size) {
        return (pos + offset) % size;
    }
};

int main() {
    int test_array[] {};
    int size = sizeof(test_array) / sizeof(int);
    int target = 5;

    Solution sol;
    cout << sol.search(test_array, size, target) << endl;
    return 0;
}
