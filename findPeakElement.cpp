#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int size = num.size();
        if(size == 0) return -1;
        int l = 0, r = size - 1;
        while(l <= r) {
            if(l == r) return l;
            int mid = (l + r) / 2;
            if(num[mid] < num[mid + 1]) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};

int main() {

    return 0;
}
