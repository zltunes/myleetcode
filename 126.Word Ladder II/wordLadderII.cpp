#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

using vs = vector<string>;
using vvs = vector<vs>;

class Solution {
    using vs = vector<string>;
    using vvs = vector<vs>;
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(end);
        deque<vs> q {vs {start}}; 
        bool find_flag = false;

        vvs ret;
        while(!find_flag && !q.empty()) {
            vvs t {q.begin(), q.end()};
            /*for(auto &v : t) {
                for(auto &item : v)
                    cout << item << ' ';
                cout << endl;
            }*/
            q.clear();

            vs eraser;
            for(auto &v : t) {
                auto item = v.back();
                if(v.back() == end) {
                    find_flag = true;
                    ret.push_back(v);
                    continue;
                }
                for(int i = 0; i < item.size(); ++i) {
                    for(char c = 'a'; c <= 'z'; ++c) {
                        if(c == item[i]) continue;
                        string t = item;
                        t[i] = c;
                        if(dict.count(t)) {
                            v.push_back(t);
                            q.push_back(v);
                            v.pop_back();
                            eraser.push_back(t);
                        }
                    }
                }
            }
            for(auto &word : eraser)
                dict.erase(word);
        }

        return ret;
    }
};

int main() {
    string start = "hit";
    string end = "cog";
    unordered_set<string> dict {"hot", "dot", "dog", "lot", "log"};

    Solution sol;
    vvs ret = sol.findLadders(start, end, dict);

    for(auto &v : ret) {
        for(auto &item : v)
            cout << item << ' ';
        cout << endl;
    }

    return 0;
}
