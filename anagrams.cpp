#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> vec;
        unordered_map<string, vector<string>> map;
        for(vector<string> :: iterator it = strs.begin(); it != strs.end(); ++it) {
            string temp = *it;
            sort(temp.begin(), temp.end());
            map[temp].push_back(*it);
        }
        for(auto kv : map) {
            if(kv.second.size() > 1) {
                vec.insert(vec.end(), kv.second.begin(), kv.second.end());
            }
        }
        return vec;
    }
};


int main() {
    Solution sol;
    vector<string> strs = {"", "", "abcd", "dbac", "ccd", "dec"};
    vector<string> ana = sol.anagrams(strs);
    for(auto str : ana) {
        cout << str << endl;
    }
    return 0;
}
