#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.size() == 1) return num.front();
        for(auto it = num.begin() + 1; it != num.end(); ++it) {
            if(*it < *(it - 1)) return *it;
        }
        return num.front();
    }
};

int main() {
    vi test {3,3,3,3,3,3};
    Solution sol;
    cout << sol.findMin(test) << endl;
    return 0;

    return 0;
}
