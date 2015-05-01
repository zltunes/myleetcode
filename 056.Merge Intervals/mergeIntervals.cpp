#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
using vI = vector<Interval>;

class Solution {
    using vI = vector<Interval>;
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.start < b.start; });
        vI ret { intervals.front() };
        for(auto it = intervals.begin() + 1; it < intervals.end(); ++it) {
            if(ret.back().end >= it->start)
                ret.back().end = max(ret.back().end, it->end);
            else 
                ret.push_back(*it);
        }
        return ret;
    }
};

int main() {
    vI test { Interval(18,39), Interval(1,2), Interval(2,9), Interval(-1, 6) };
    Solution sol;
    vI ret = sol.merge(test);
    for(auto &itv : ret) {
        cout << itv.start << ' ' << itv.end << endl;
    }
    return 0;
}
