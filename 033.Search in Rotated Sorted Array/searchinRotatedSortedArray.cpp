#include <iostream>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int head = findPeak(A, 0, n - 1);
        int tail = 0;
        if(head) tail = head - 1;
        int l = 0, r = n - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int c_mid = change(head, mid, n);
            if(A[c_mid] == target) return c_mid;
            if(A[c_mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

    inline int change(int head, int origin, int size) {
        return (origin + head) % size;
    }
    int findPeak(int A[], int l, int r) {
        while(l < r) {
            if(A[l] > A[l + 1])
                return l + 1;
            ++l;
        }
        return 0;
    }
};

int main() {
    int test[] = {5,6,7,0,1,2,3};
    int size = sizeof(test) / sizeof(int);

    Solution sol;
    cout << sol.search(test, size, 0) << endl;
    return 0;
}
