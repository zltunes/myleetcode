#include <iostream>
#include <functional>
#include <cstring>
using namespace std;
#define DEBUG

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p == 0) return (*s == 0);

        if(*(p + 1) == '*') {
            while(*s != 0 && isCharMatch(*s, *p)) {
                if(isMatch(s, p + 2)) {
                    return true;
                }
                ++s;
            }
            return isMatch(s, p + 2);
        }
        else {
            if(*s != 0 && isCharMatch(*s, *p)) {
                return isMatch(s + 1, p + 1);
            }
        }
        return false;
    }
    bool isMatch2(const char *s, const char *p) {
        const char *ps = s;
        char *t = new char[strlen(p) + 1];
        strcpy(t, p);
        const char *pp = t;
        while(*t != 0) {
            if(*t == '*') {
                char *move = t + 1; 
                while(*move != 0 && *move == *(t - 1)) {
                    *(move - 1) = *(t - 1);
                    ++move;
                }
                *(move - 1) = '*';
            }
            ++t;
        }
        cout << pp << endl;
        while(*ps != 0 && *pp != 0) {
#ifdef DEBUG
            cout << "begin turn" << endl;
            cout << *ps << ' ' << *pp << endl;
#endif
            if(*(pp + 1) == '*') {
                while(isCharMatch(*ps, *pp)){
#ifdef DEBUG
                    cout << "inner turn" << endl;
                    cout << *ps << ' ' << *pp << endl;
#endif
                    ++ps;
                }
                pp += 2;
            }
            else {
                if(!isCharMatch(*ps, *pp)) {
                    return false;
                }
                else {
                    ++ps;
                    ++pp;
                }
            }
#ifdef DEBUG
            cout << "end turn" << endl;
#endif
        }
        if(strcmp(pp, ".*") == 0)
            return true;
        if(*pp == 0 && *ps == 0) {
            return true;
        }
        return false;
    }

    bool isCharMatch(char cs, char cp) {
        if(cs == 0) return false;
        if(cp == '.') {
            return true;
        }
        return (cs == cp);
    }
};

int main() {

    Solution sol;
    cout << sol.isMatch("abs", "abs*") << endl;
    return 0;
}
