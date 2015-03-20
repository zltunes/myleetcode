#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

class Solution {
    using vi = vector<int>;
public:
    int majorityElement(vector<int> &num) {
        int number_record, number_count;
        number_count = 0;
        for(auto &item : num) {
            if(number_count == 0) number_record = item;
            if(item == number_record) {
                ++number_count;
            }
            else {
                --number_count;
            }
        }
        return number_record;
    }
};

int main() {
    vi test {1,1,1,1,2,2,2,6,7,2,2,2,2,2,3};

    cout << test.size() << endl;
    Solution sol;
    cout << sol.majorityElement(test) << endl;
    return 0;
}
