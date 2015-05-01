#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        gas.insert(gas.end(), gas.begin(), gas.end());
        cost.insert(cost.end(), cost.begin(), cost.end());
        int store_gas = 0;
        int cnt = 0;
        for(int i = 0; i < gas.size(); ++i) {
            store_gas += gas[i];
            store_gas -= cost[i];
            ++cnt;
            if(store_gas < 0) {
                store_gas = 0;
                cnt = 0;
                if(i >= gas.size() / 2) {
                    return -1;
                }
            }
            if(cnt == gas.size() / 2) {
                return i + 1 - cnt;
            }
        }
        return -1;
    }
};

int main() {

    vi gas {2,4,5,9,1};
    vi cost {3,3,7,3,1};
    Solution sol;
    cout << sol.canCompleteCircuit(gas, cost) << endl;

    return 0;
}
