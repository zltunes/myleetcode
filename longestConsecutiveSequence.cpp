#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

using vi = vector<int>;

class Solution {
    using usi = unordered_set<int>;
public:
    int longestConsecutive(vector<int> &num) {
        usi nums;
        for(auto &item : num)
            nums.insert(item);

        int ret = 0;
        for(auto &item : num) {
            int left, right;
            left = right = item;
            if(!nums.count(item)) continue;
            else nums.erase(item);
            while(nums.count(--left)) nums.erase(left);
            while(nums.count(++right)) nums.erase(right);
            ret = max(ret, right - left - 1);
        }
        return ret;
    }
};

int main() {
    vi test {};

    Solution sol;
    cout << sol.longestConsecutive(test) << endl;

    return 0;
}
