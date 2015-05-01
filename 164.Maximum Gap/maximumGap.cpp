#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

using vi = vector<int>;
void printVI(const vi &nums);

class Solution {
    using vi = vector<int>;
public:
    int maximumGap(vector<int>& nums) {
        return qsort_solution(nums);
    }

    int qsort_solution(vi & nums) {
        int size = nums.size();
        if(size < 2) return 0;
        sort(nums.begin(), nums.end());

        int max_gap = 0;
        for(auto it = nums.begin() + 1; it < nums.end(); ++it)
            max_gap = max(max_gap, (*it - *(it - 1)));
        return max_gap;
    }
};

void printVI(const vi &nums) {
    for(auto &item : nums)
        cout << item << ' ';
    cout << endl;
}

vi genArrary(int num = 10) {
    random_device rd;
    default_random_engine e(rd());
    uniform_int_distribution<> u(1, num);
    vi ret(num, 0);
    for(auto &item : ret)
        item = u(e);
    return ret;
}

int main() {
    vi test = genArrary();
    printVI(test);

    Solution sol;
    cout << sol.maximumGap(test) << endl;
    return 0;
}
