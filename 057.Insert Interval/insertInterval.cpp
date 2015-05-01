#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

using vI = vector<Interval>;

void printIntervals(vI &intervals);

class Solution {
    using vI = vector<Interval>;
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int size = intervals.size() * 2;
        vI ret;
        int ll, lr;
        ll = 0, lr = size - 1;
        while(ll <= lr) {
            int mid = (ll + lr) / 2;
            int mid_val = getNumInterval(intervals, mid);
            if(mid_val < newInterval.start) ll = mid + 1;
            else lr = mid - 1;
        }

        int rl, rr;
        rl = 0, rr = size - 1;
        while(rl <= rr) {
            int mid = (rl + rr) / 2;
            int mid_val = getNumInterval(intervals, mid);
            if(mid_val <= newInterval.end) rl = mid + 1;
            else rr = mid - 1;
        }


        int start_index, is_start_end, end_index, is_end_end;
        start_index = ll / 2, is_start_end = ll % 2;
        end_index = rl / 2, is_end_end = rl % 2;
        
        if(ll == rl && is_start_end == 0) {
            intervals.insert(intervals.begin() + start_index, newInterval);
        }
        else {
            if(is_end_end == 0) --end_index;
            if(is_start_end)
                intervals[end_index].start = intervals[start_index].start;
            else
                intervals[end_index].start = newInterval.start;
            if(is_end_end == 0)
                intervals[end_index].end = newInterval.end;

            intervals.erase(intervals.begin() + start_index, intervals.begin() + end_index);
        }

        //printIntervals(intervals);
        return intervals;
    }

    int getNumInterval(vI &intervals, int index) {
        auto cur = intervals[index / 2];
        return index % 2 ? cur.end : cur.start;
    }
};


vI genRandomIntervals(int max_num = 10) {
    vI ret;
    int cnt = 1;
    for(int i = 0; i < max_num; ++i) {
        int start = cnt;
        cnt += rand() % max_num;
        ret.push_back(Interval {start, cnt});
        cnt += rand() % max_num + 1;
    }
    return ret;
}

void printIntervals(vI &intervals) {
    for(auto & item : intervals)
        cout << "(" << item.start << ", " << item.end << ") ";
    cout << endl;
}

int main() {
    srand(time(NULL));
    vI intervals = genRandomIntervals(0);
    Interval insertion {1, 3};

    printIntervals(intervals);

    Solution sol;

    vI ret = sol.insert(intervals, insertion);
    printIntervals(ret);
    return 0;
}
