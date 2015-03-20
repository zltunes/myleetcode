#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        solution1(nums, n, k);    
        //solution2(nums, n, k);    
    }

    void solution1(int nums[], int n, int k) {
        if(n == 0 || n == 1) return;
        k = k % n;
        if(k == 0) return;
        int i, j;  
        i = 0, j = n - 1;
        while(i < j) swap(nums[i], nums[j]), ++i, --j;
        i = 0, j = k - 1;
        while(i < j) swap(nums[i], nums[j]), ++i, --j;
        i = k, j = n - 1;
        while(i < j) swap(nums[i], nums[j]), ++i, --j;
    }
    void solution2(int nums[], int n, int k) {
        int *new_nums = new int[n];
        for(int i = 0; i < n - k; ++i)
            new_nums[k + i] = nums[i];
        for(int i = n - k; i < n; ++i)
            new_nums[i - k - 1] = nums[i];
        for(int i = 0; i < n; ++i)
            nums[i] = new_nums[i];
    }
    void solution3(int nums[], int n, int k) {
    
    }
};

int main() {
    int test[] = {1,2,3,4,5,6,7};
    const int size_test = sizeof(test) / sizeof(int);
    Solution sol;
    sol.rotate(test, size_test, 3);

    for(int i = 0; i < size_test; ++i) {
        cout << test[i] << ' ';
    }
    cout << endl;
    return 0;
}
