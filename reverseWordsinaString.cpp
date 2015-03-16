#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    using vs = vector<string>;
public:
    void reverseWords(string &s) {
        int i, j;
        i = 0, j = s.size() - 1;
        while(s[i] == ' ') ++i;
        while(s[j] == ' ') --j;
        s.erase(j + 1);
        s.erase(0, i);
        i = 0, j = s.size() - 1;
        while(i < j) {
            swap(s[i], s[j]);
            ++i, --j;
        }
        i = 0;
        while(i < s.size()) {
            int space_begin = i;
            while(s[i] == ' ') ++i;
            if(i > space_begin) {
                s.erase(space_begin, i - space_begin);
                i = space_begin;
            }
            int begin = i;
            while(i < s.size() && s[i] != ' ') ++i;
            int end = i - 1;
            while(begin < end) {
                swap(s[begin], s[end]);
                ++begin, --end;
            }
            ++i;
        }
    }
};

int main() {
    string test = "  dad  sa     dda  sda ";
    cout << test << endl;
    Solution sol;
    sol.reverseWords(test);
    cout << '1' << test << '1' << endl;
    return 0;
}
