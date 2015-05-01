#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
using vi = vector<int>;

class Solution {
    using vi = vector<int>;
public:
    int rob(vector<int> &num) {
        int size = num.size();
        if(size == 0) return 0;
        if(size == 1) return num.front();
        if(size == 2) return max(num[0], num[1]);
        num[1] = max(num[1], num[0]);
        for(int i = 2; i < size; ++i) {
            num[i] = max(num[i - 2] + num[i], num[i - 1]);
        }
        return num.back();
    }
};

vi genRandomArray(int max = 4) {
    vi ret;
    for(int i = 0; i < max; ++i) {
        ret.push_back(rand() % max + 1);
    }
    return ret;
}

int main() {
    srand(time(NULL));
    vi test = genRandomArray();
    for(auto & item : test)
        cout << item << ' ';
    cout << endl;

    Solution sol;
    cout << sol.rob(test) << endl;
    return 0;
}
