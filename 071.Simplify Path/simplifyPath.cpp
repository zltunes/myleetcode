#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss;
        ss.str(path);
        string now;
        vector<string> stk;
        while(getline(ss, now, '/')) {
            cout << now << endl;
            if(now.size() == 0 || now == ".") {
                continue;
            }
            if(now == "..") {
                if(stk.empty()) continue;
                stk.pop_back();
            }
            else
                stk.push_back(now);
        }
        string ret;
        for(auto &item : stk) {
            ret.append("/" + item);
        }
        if(ret.size() == 0)
            ret = "/";
        return ret;
    }
};

int main() {
    Solution sol;
    cout << sol.simplifyPath("/home/../foo/./.././bar/..///") << endl;
    return 0;
}
