#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    typedef vector<int> vi;
    int maxArea(vector<int> &height) {
        if(height.size() <= 1) return 0;
        int i = 0;
        int j = height.size() - 1;
        int max_volume = 0;
        while(i < j) {
            int volume = min(height[i], height[j]) * (j - i);
            if(volume > max_volume) {
                max_volume = volume;
            }
            if(height[i] < height[j]) {
                ++i;
            }
            else {
                --j;
            }
        }
        return max_volume;
    }
};

int main() {
    vector<int> vec {1,2,3,4,5};
    Solution sol;
    cout << sol.maxArea(vec) << endl;
    return 0;
}
