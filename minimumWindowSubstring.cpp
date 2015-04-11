#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        string ret;

        int i, j = 0;
        int size = S.size();

        while(j < size && !isInT(S[j], T)) ++j;
        i = j;
        int check[256] = {0};
        for(auto &chr : T)
            ++check[static_cast<int>(chr)];

        S.push_back('#');
        int cnt = 0;
        int min_length = size;
        int min_start, min_end;
        min_start = min_end = 0;
        while(i < size) {
            if(cnt == T.size()) {
                if(j - i <= min_length) {
                    min_length = j - i;
                    min_start = i;
                    min_end = j;
                    /*cout << "min_length is : " << min_length << endl;
                    cout << "word range is : " << S.substr(i, j - i) << endl;*/
                }
                if(check[static_cast<int>(S[i])] >= 0)
                    --cnt;
                ++check[static_cast<int>(S[i])];
                ++i;
                while(i < size && !isInT(S[i], T)) {
                    ++i;    
                }
            }
            else {
                if(isInT(S[j], T)) {
                    --check[static_cast<int>(S[j])];
                    if(check[static_cast<int>(S[j])] >= 0)
                        ++cnt;
                }
                if(S[j] != '#')
                    ++j;
                else
                    ++i;
            }
            /*cout << i << ' ' << j << endl;
            cout << S[i] << ' ' << S[j] << endl;
            cout << "cnt : " << cnt << endl;

            for(auto &chr : T)
                cout << chr << " : " << check[static_cast<int>(chr)] << endl;
            getchar();*/
        }

        return S.substr(min_start, min_end - min_start);
    }


    bool isInT(char s, string T) {
        return T.find(s) != string::npos;
    }
};

int main() {
    string S = "abdasdasfc";
    string T = "abc";

    Solution sol;
    cout << sol.minWindow(S, T) << endl;
    return 0;
}
