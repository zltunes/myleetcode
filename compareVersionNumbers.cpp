#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
    using vi = vector<int>;
public:
    int compareVersion(string version1, string version2) {
        vi ret1 = getContent(version1);
        vi ret2 = getContent(version2);
        int size = min(ret1.size(), ret2.size());
        int i = 0;
        for(; i < size; ++i) {
            if(ret1[i] == ret2[i]) continue;
            if(ret1[i] > ret2[i]) return 1;
            else return -1;
        }
        while(i < ret1.size()) {
            if(ret1[i] != 0) return 1;
            ++i;
        }
        while(i < ret2.size()) {
            if(ret2[i] != 0) return -1;
            ++i;
        }
        return 0;
    }
    vi getContent(string version) {
        stringstream ss;
        ss.str(version);
        vi ret;
        while(getline(ss, version, '.')) {
            ret.push_back(stoi(version)); 
        }
        return ret;
    }
};


int main() {
    string test1 = "1.1.0.0";
    string test2 = "1.1";

    Solution sol;
    cout << sol.compareVersion(test1, test2) << endl;
    return 0;
}
