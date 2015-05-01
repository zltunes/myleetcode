#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        this->target = target;
        sort(num.begin(), num.end());
        nums = num;
        vector<int> temp;
        vector<vector<int> > ret;
        findNumber(temp, 0, -1);
        return this->ret;
    }

    void findNumber(vector<int> & array, int sum, int pos) {
        for(int i = pos + 1; i < nums.size(); ++i) {
            if(sum + nums[i] == target) {
                array.push_back(target - sum);
                string sign = to_string(array);
                if(check.count(sign) == 0) {
                    ret.push_back(array);
                    check.insert(sign);
                }
                array.pop_back();
            }
            if(sum + nums[i] < target) {
                array.push_back(nums[i]);
                findNumber(array, sum + nums[i], i);
                array.pop_back();
            }
        } 
    }
    string to_string(vector<int> & vec) {
        string ret = "";
        for(auto num : vec) {
            ret += ::to_string(num);
        }
        return ret;
    }

    Solution() : target(0) {}
private:
    unordered_set<string> check;
    vector<vector<int> > ret;
    vector<int> nums;
    int target;
};

int main() {
    vector<int> vec = {10,1,2,7,6,1,5};
    Solution sol;
    vector<vector<int> > sols = sol.combinationSum2(vec, 8);
    for(auto sol : sols) {
        for(auto num : sol) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
