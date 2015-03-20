#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

using vs = vector<string>;
using vi = vector<int>;

class Solution {
    using vs = vector<string>;
    using vi = vector<int>;
public:
    string largestNumber(vector<int> &num) {
        vs vec;
        for(auto &item : num) {
            vec.push_back(to_string(item));
        }
        /*
        struct {
            bool operator() (string a, string b) {
                int i, j;
                i = 0, j = 0;
                while(i < a.size() && j < b.size()) {
                    if(a[i] != b[j]) return a[i] < b[j];
                    ++i, ++j;
                }
                while(i < a.size()) {
                    if(a[i] != b.back()) return a[i] < b.back();
                    ++i;
                }
                while(j < b.size()) {
                    if(a.back() != b[j]) return a.back() < b[j];
                    ++j;
                }
                return a.back() < b.back();
            }
        } stringComp;*/

        struct {
            bool operator() (string a, string b) {
                string a_first = a + b;
                string b_first = b + a;
                return a_first < b_first;
            }
        } stringComp;
        sort(vec.begin(), vec.end(), stringComp);
        string ret;
        if(vec.back() == "0") return "0";
        for(auto it = vec.rbegin(); it != vec.rend(); ++it) {
            ret.append(*it);
        }
        return ret;
    }
};

int main() {
    vi test {0,0,1,12,33,3,98,30,34,5,9};
    //vi test {824,8247};
    Solution sol;
    cout << sol.largestNumber(test) << endl;
    return 0;
}
