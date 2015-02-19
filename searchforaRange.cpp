#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

class Solution {
    typedef vector<int> vi;
public:
    vector<int> searchRange(int A[], int n, int target) {
        vi ret { -1, -1 };
        if(n == 0) return ret;
        int ll = 0, lr = n - 1;
        while(ll <= lr) {
            int mid = (ll + lr) / 2;
            if(A[mid] < target) {
                ll = mid + 1;
            }
            else {
                lr = mid - 1;
            }
        }
        int rl = 0, rr = n - 1;
        while(rl <= rr) {
            int mid = (rl + rr) / 2;
            if(A[mid] <= target) {
                rl = mid + 1;
            }
            else {
                rr = mid - 1;
            }
        }
        if(ll <= rr) {
            ret[0] = ll;
            ret[1] = rr;
        } 
        return ret;
    }
};

int main() {
    Solution sol;
    int A[] = {8,8,8,8};
    int target = 7;
    const int SIZE_INT = sizeof(int);
    vi ret = sol.searchRange(A, sizeof(A) / SIZE_INT, target);
    cout << ret[0] << ' ' << ret[1] << endl;
    return 0;
}
