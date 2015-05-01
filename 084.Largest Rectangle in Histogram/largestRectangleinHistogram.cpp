#include <iostream>
#include <vector>
#include <climits>
using namespace std;

using vi = vector<int>;

class Solution {
    using pii = pair<int, int>;
    using vpii = vector<pii>;
public:
    int largestRectangleArea(vector<int> &height) {
        vpii stk; 
        height.push_back(0);

        int max_rect = 0;
        int size = height.size();

        for(int i = 0; i < size; ++i) {
            if(stk.empty() || height[i] >= stk.back().first)
                stk.push_back(make_pair(height[i], i));
            else {
                while(!stk.empty() && stk.back().first > height[i]) {
                    auto t = stk.back(); stk.pop_back();
                    int width = stk.empty() ? i : (i - stk.back().second - 1);
                    max_rect = max(max_rect, width * t.first);
                }
                stk.push_back(make_pair(height[i], i));
            } 
            /*cout << "stack situation: " << endl;
            for(auto &item : stk)
                cout << item.first << ' ' << item.second << endl;
            cout << endl;*/
        }
        return max_rect;
    }
};

int main() {
    //vi test {2,1,5,6,2,3};    
    vi test {4,2,0,3,2,5};    
    //vi test {6,7,8,9,7,6};    
    //vi test {0,9};    
    //vi test {1,2,2};    
    //vi test {2,1,2};    

    Solution sol;
    cout << sol.largestRectangleArea(test) << endl;
    return 0;
}
