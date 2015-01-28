#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    typedef vector<int> vi;
    int threeSumClosest(vector<int> &num, int target) {
        if(num.size() <= 2) return INT_MAX;
        sort(num.begin(), num.end());
        int distance = INT_MAX;
        int closest_sum = -1;
        for(int cnt = 0; cnt < num.size() - 2; ++cnt) {
            int i = cnt + 1;
            int j = num.size() - 1;
            while(i < j) {
                int three_sum = num[i] + num[j] + num[cnt];
                int t = three_sum > target ? three_sum - target : target - three_sum;
                if(t < distance) {
                    distance = t;
                    closest_sum = three_sum;
                }
                if(three_sum > target) --j;
                if(three_sum < target) ++i;
                if(three_sum == target) {
                    return target;
                }
            }
        }
        return closest_sum;
    }
};

int main() {
    vector<int> test = {-1, 2, 1, 4};
    int target = 1;
    Solution sol;
    cout << sol.threeSumClosest(test, target) << endl;
    return 0;
}
