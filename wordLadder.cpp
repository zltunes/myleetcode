#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    typedef pair<string, int> sipair;

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<sipair> mQueue;
        mQueue.push(make_pair(start, 1));
        dict.insert(end);
        while(!mQueue.empty()) {
            sipair t = mQueue.front();
            mQueue.pop();
            if(t.first == end)
                return t.second;
            string &str = t.first;
            string temp;
            for(int i = 0; i < str.size(); ++i) {
                temp = str;
                for(char chr = 'a'; chr < 'z'; ++chr) {
                    temp[i] = chr;
                    if(dict.count(temp) != 0 && temp != str) {
                        mQueue.push(make_pair(temp, t.second + 1)); 
                        dict.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    unordered_set<string> mSet = {"hot","dot","dog","lot","log"};
    //unordered_set<string> mSet = {"hot","dog"};
    Solution sol;
    cout << sol.ladderLength("hit", "cog", mSet);
    return 0;
}
