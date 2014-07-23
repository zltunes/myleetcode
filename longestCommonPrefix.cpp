#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        int length = INT_MAX;
        for(vector<string> :: iterator it = strs.begin(); it != strs.end(); ++it) {
            if(it->length() < length)
                length = it->length();
        }
        string & first = *strs.begin();
        string & second = *(strs.begin() + 1);
        int cnt = 0;
        while(cnt < first.length() && cnt < second.length() && first[cnt] == second[cnt]) {
            cnt++;
        }
        string pattern = first.substr(0, cnt);
        //cout << "Pattern: " << pattern << endl;
        if(cnt == 0) return pattern;
        vector<string> :: iterator it = strs.begin() + 2;
        while(it != strs.end()) {
            string & temp = *it;
            if(temp.length() < cnt) {
                cnt = temp.length();
                pattern = pattern.substr(0, cnt);
            }
            int tCnt = 0;
            while(tCnt < temp.length() && tCnt < pattern.length() && temp[tCnt] == pattern[tCnt]) {
                tCnt++;    
            }
            pattern = pattern.substr(0, tCnt);
            if(tCnt == 0) return pattern;
            ++it;
        } 
        return pattern;
    }
};

int main() {
    vector<string> testVec = {"12","12","12"};
    Solution sol;
    cout << sol.longestCommonPrefix(testVec) << endl;
    return 0;
}
