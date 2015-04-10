#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    using mpci = unordered_map<char, int>;
public:
    string minWindow(string S, string T) {
        int max_length = 0;
        string ret;

        int i, j = 0;
        while(!isInT(S[j], T)) ++j;
        i = j;
    }

    bool isInT(char s, string T) {
        return T.find(s) != string::npos;
    }
};

int main() {

    return 0;
}
