#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carried = true;
        digits.insert(digits.begin(), 0);
        for(auto it = digits.rbegin(); it != digits.rend(); ++it) {
            if(carried) {
                *it += 1;
                carried = false;
            }
            if(*it == 10) {
                *it = 0;
                carried = true;
            }
            if(carried == false) break;
        }
        if(digits[0] == 0) digits.erase(digits.begin());
        return digits;
    }
};

int main() {
    vector<int> vec = {9,9,9,9};
    Solution sol;
    sol.plusOne(vec);
    for(auto &item : vec) {
        cout << item;
    }
    cout << endl;
    return 0;
}
