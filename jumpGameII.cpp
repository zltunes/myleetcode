#include <iostream>
#include <deque>
#include <ctime>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        return jump_backward(A, n);
    }

    int jump_forward(int A[], int n) {
        int ret, last, curr;
        ret = last = curr = 0;
        for(int i = 0; i < n; ++i) {
            if(i > curr) return -1;
            if(i > last) {
                last = curr;
                ++ret;
            }
            curr = max(curr, A[i] + i);
        }
        return ret;
    }

    int jump_backward(int A[], int n) {
        int cnt = 0;
        int cur = n - 1;
        int pre = 0;
        while(pre != cur) {
            pre = cur;
            for(int i = pre - 1; i >= 0; --i) {
                if(A[i] + i >= pre) {
                    if(i < cur) 
                        cur = i;
                }
            }
            ++cnt;
            if(cur == 0) return cnt;
        }
        return 0;
    }
};



int jump_dp(int A[], int n) {
    int *dp = new int[n];
    dp[0] = 0;
    for(int i = 1; i < n; ++i) {
        dp[i] = INT_MAX;
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(j + A[j] >= i) {
                int t = dp[j] + 1;
                if(t < dp[i]) {
                    dp[i] = t;
                    break;
                }
            }
        }
    }
    return dp[n - 1];
}

int main() {
    //int test[] = {2,3,1,1,4};
    int test[] = {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    int size = sizeof(test) / sizeof(int);
    Solution sol;

    auto start = clock();
    cout << "jump forward" << endl;
    cout << sol.jump_forward(test, size) << endl;
    cout << clock() - start << endl;
    
    start = clock();
    cout << "jump backward" << endl;
    cout << sol.jump_backward(test, size) << endl;
    cout << clock() - start << endl;

    return 0;
}
