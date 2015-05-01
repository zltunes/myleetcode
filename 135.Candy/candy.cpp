#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int size = ratings.size();
        if(size == 0) return 0;
        vector<int> candy(size, 1);
        for(int i = 1; i < size; ++i) {
            if(ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }
        for(int i = size - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i + 1]) {
                candy[i] = max(candy[i + 1] + 1, candy[i]);
            }
        }
        int sum = 0;
        for(auto item : candy) {
            sum += item;
        }
        return sum;
    }
};

int main() {
    vector<int> vec = {1,2,4,4,3};
    Solution sol;
    cout << sol.candy(vec);
    return 0;
}
