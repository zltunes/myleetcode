#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef unordered_map<string, int> msi;

void printVI(const vi & vec);

class Solution {
    typedef vector<string> vs;
    typedef vector<int> vi;
    typedef unordered_map<string, int> msi;
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        if(L.empty()) return vi {};
        int word_length = L.front().length();
        vi ret;
        msi origin_dic;
        for(auto & word : L) {
            if(origin_dic.count(word) == 0)
                origin_dic[word] = 1; 
            else
                origin_dic[word] += 1;
        }
        int word_size = L.size();
        for(int offset = 0; offset < word_length; ++offset) {
            int i = offset, j = offset;
            int cnt = 0;
            msi dic = origin_dic;
            while(j < S.size()) {
                string temp = S.substr(j, word_length);

                if(dic.count(temp) == 0) {
                    while(i < j) {
                        dic[S.substr(i, word_length)] += 1;
                        i += word_length;
                    }
                    cnt = 0;
                    j += word_length;
                    i = j;
                } 
                else if(dic[temp] == 0) {
                    while(dic[temp] == 0) {
                        dic[S.substr(i, word_length)] += 1;
                        i += word_length;
                        --cnt;
                    }
                }
                else {
                    dic[temp] -= 1;
                    j += word_length;
                    ++cnt;
                }
                if(cnt == word_size) {
                    ret.push_back(i);
                }
            }
        }
        return ret;
    }
};

void printVI(const vi & vec) {
    for(auto & item : vec) {
        cout << item << ' ';
    }
    cout << endl;
}

int main() {
    vs L = {"aa","aa", "aa"};
    string S = "aaaaaaaa";
    Solution sol;
    printVI(sol.findSubstring(S, L));
    return 0;
}
