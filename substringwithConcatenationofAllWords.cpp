#include <iostream>
#include <vector>
using namespace std;

typedef vector<string> vs;

class Solution {
    typedef vector<string> vs;
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        string ret;
        for(auto & str :L) {
            ret.push_back(str[0]); 
        }
        int indice = 0;
        while(indice < S.length()) {
            int pos = ret.find_first_of(S[indice]);
        }

    }
};


int main() {
    vs test = {"foo", "bar", "man"};
    string combine {test.begin(), test.end()};
    cout << combine << endl;
    return 0;
}
