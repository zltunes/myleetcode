#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

using vPoint = vector<Point>;

class Solution {
    using MAP = unordered_map<double, int>;
public:
    int maxPoints(vector<Point> &points) {
        MAP table;
        int size = points.size();
        if(size == 0) return 0;

        int ret = 1;
        for(int i = 0; i < size - 1; ++i) {
            int horizon = 0;
            int same = 1;
            table.clear();
            auto &p1 = points[i];
            for(int j = i + 1; j < size; ++j) {
                auto &p2 = points[j];
                if(p1.x == p2.x && p1.y == p2.y) {
                    same += 1;
                    continue;
                }
                if(p1.x - p2.x == 0) horizon += 1; 
                else {
                    double k = static_cast<double>(p1.y - p2.y) / (p1.x - p2.x);
                    table[k] += 1;
                }
            }
            cout << p1.x << ' ' << p1.y << endl;
            cout << horizon + same << endl;
            ret = max(ret, horizon + same);
            for(auto &kv : table) {
                cout << kv.first << ' ' << kv.second + same << endl;
                ret = max(ret, kv.second + same);
            }
            cout << endl;
        }
        return ret;
    }
};

int main() {
    vPoint points {
        Point(84,250),
        Point(0,0),
        Point(1,0),
        Point(0,-70),
        Point(0,-70),
        Point(1,-1),
        Point(21,10),
        Point(42,90),
        Point(-42,-230)
    };


    Solution sol;
    cout << sol.maxPoints(points) << endl;
    return 0;
}
