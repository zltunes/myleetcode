#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        if(s.length() == 1)
            return 1;

        bool exists[256] = { false };
        int i, j, max_length;
        max_length = 0;
        i = 0, j = 0;
        while(j != s.length()) {
            if(exists[s[j]] == true) {
                max_length = max(j - i, max_length);
                while(s[i] != s[j]) {
                    exists[s[i]] = false;
                    ++i;
                }
                ++i;
            }
            else {
                exists[s[j]] = true;
            }
            ++j;
        }
        max_length = max(j - i, max_length);
        return max_length;
    }
};


int main() {
    string s = "wcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayulyeimuotehzriicfskpggkbbipzzrzucxamludfyk";
    //string s = "abcabcbb";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}
