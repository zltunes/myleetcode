#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring_new(string s) {
        int size = s.size();
        if(size == 0) return 0;
        bool table[256] = { false };

        int i, j, max_length;
        i = j = max_length = 0;
        while(j < size) {
            if(table[s[j]]) {
                max_length = max(max_length, j - i);
                while(s[i] != s[j]) {
                    table[s[i]] = false;
                    ++i;
                }
                ++i;
            }
            else
                table[s[j]] = true;
            ++j;
        }
        max_length = max(max_length, j - i);
        return max_length;
    }
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
    cout << sol.lengthOfLongestSubstring_new(s) << endl;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}
