#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(s == NULL) return 0;
        int indice = strlen(s) - 1;
        while(indice >= 0 && s[indice] == ' ') --indice;
        if(indice < 0) return 0;
        int cnt = 0;
        while(indice >= 0 && s[indice] != ' ') {
            --indice;
            ++cnt;
        }
        return cnt;
    }
};


int main() {
    const char *s = " Asdad";
    Solution sol;
    cout << sol.lengthOfLastWord(s) << endl;
    return 0;
}
