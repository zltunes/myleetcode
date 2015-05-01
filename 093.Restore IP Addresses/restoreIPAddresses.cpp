#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<string> vs;

class Solution {
    typedef vector<string> vs;
public:
    vector<string> restoreIpAddresses(string s) {
        vs ret; 
        worker(ret, 0, 0, s);
        return ret;
    }

    void worker(vs &ret, int level, int pos, string s) {
        if(level == 3) {
            if(s.size() - pos > 3) return;
            else {
                string t = s.substr(pos, 3);
                if(t[0] == '0' && t.size() != 1) return;
                if(stoi(t) <= 255) {
                    ret.push_back(s);
                }
            }
            return;
        } 
        if(s[pos] == '0') {
            string temp = s;
            if(pos + 1 >= s.size()) return;
            temp.insert(pos + 1, 1, '.');
            worker(ret, level + 1, pos + 2, temp);
            return;
        }
        for(int i = pos; i < pos + 3; ++i) {
            if(i == pos + 2) {
                if(stoi(s.substr(pos, 3)) > 255) {
                    continue;
                }
            }
            string temp = s;
            if(i + 1 >= s.size()) return;
            temp.insert(i + 1, 1, '.');
            worker(ret, level + 1, i + 2, temp);
        }
    }
};

int main() {
    string ip = "010010";
    Solution sol;
    vs ret = sol.restoreIpAddresses(ip);
    for(auto & s : ret) {
        cout << s << endl;
    }
    return 0;
}
