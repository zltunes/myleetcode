#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch_recursive(const char *s, const char *p) {
        if(*p == 0) return (*s == 0);
        if(*p == '*') {
            while(*(p + 1) == '*') ++p;
            while(*s != 0) {
                if(isMatch(s, p + 1))
                    return true;
                s++;
            }
            return isMatch(s, p + 1);
        }
        else {
            if(*s != 0 && (*s == *p || *p == '?')) {
                return isMatch(s + 1, p + 1);
            }
        }
        return false;
    }

    bool isMatch(const char *s, const char *p) {
        const char *record_s, *star;
        record_s = NULL;
        star = NULL;
        while(*s != 0) {
            if(*s == *p || *p == '?') {
                ++s, ++p;
            }
            else if(*p == '*') {
                star = p;
                record_s = s;
                ++p;
            }
            else if(star != NULL) {
                p = star + 1;
                s = record_s + 1;
                ++record_s;
            }
            else
                return false;
        }
        while(*p == '*') ++p;
        return *p == 0;
    }
};

int main() {
    char s[] = "aabbccdde";
    char p[] = "*bbc*cdde";

    Solution sol;
    cout << sol.isMatch(s, p) << endl;
    return 0;
}
