#include <iostream>
#include <string>
#include <vector>
using namespace std;

using vs = vector<string>;

class Solution {
    using vs = vector<string>;
    using psi = pair<string, int>;
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vs ret;
        int mp[1024 * 1024] = {0};
        if(s.size() <= 10) return ret;
        string t = s.substr(0, 10); 
        auto code = encode(t);
        mp[code.second] = 1;
        for(int i = 10; i < s.size(); ++i) {
            code = move(code, s[i]);
            if(mp[code.second] == 0) mp[code.second] = 1; 
            else if(mp[code.second] == 1) {
                ret.push_back(s.substr(i - 9, 10));
                mp[code.second] = 2;
            }
        }
        return ret; 
    }

    psi move(psi code, char chr) {
        string &ret_str = code.first;
        int &ret = code.second;
        string front_2 = ret_str.substr(0, 2);
        if(front_2 == "00") ret -= 0;
        if(front_2 == "01") ret -= 1024 * 256;
        if(front_2 == "10") ret -= 1024 * 512;
        if(front_2 == "11") ret -= 1024 * 768;
        ret *= 4;
        ret_str.erase(0, 2);
        switch(chr) {
            case 'A':
                ret_str.append("00");
                ret += 0;
                break;
            case 'C':
                ret_str.append("01");
                ret += 1;
                break;
            case 'G':
                ret_str.append("10");
                ret += 2;
                break;
            case 'T':
                ret_str.append("11");
                ret += 3;
                break;
        }
        return code;
    }

    psi encode(string s) {
        int ret = 0;
        string ret_str;
        for(auto &chr : s) {
            ret *= 4;
            switch(chr) {
                case 'A':
                    ret_str.append("00");
                    ret += 0;
                    break;
                case 'C':
                    ret_str.append("01");
                    ret += 1;
                    break;
                case 'G':
                    ret_str.append("10");
                    ret += 2;
                    break;
                case 'T':
                    ret_str.append("11");
                    ret += 3;
                    break;
            }
        }
        return make_pair(ret_str, ret);
    }
};

int main() {
    string test = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution sol;
    vs ret = sol.findRepeatedDnaSequences(test);
    for(auto &seq : ret) {
        cout << seq << endl;
    }
    return 0;
}
