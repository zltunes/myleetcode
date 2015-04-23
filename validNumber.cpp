#include <iostream>
#include <string>
#include <vector>
using namespace std;
using vs = vector<string>;

class Solution {
public:
    bool isNumber(string s) {
        enum INPUT_TYPE {
            INVALID,  //begin
            SPACE,    //space
            SIGNAL,   //signal
            DIGITAL,  //digital
            DOT,      //dot
            EXPO,     //exp
            NUM_INPUT //6
        };

        int transition_table [][NUM_INPUT] = {
            {-1, 0, 3, 1, 2,-1}, // state 0
            {-1, 8,-1, 1, 4, 5}, // state 0
            {-1,-1,-1, 4,-1,-1}, // state 0
            {-1,-1,-1, 1, 2,-1}, // state 0
            {-1, 8,-1, 4,-1, 5}, // state 0
            {-1,-1, 6, 7,-1,-1}, // state 0
            {-1,-1,-1, 7,-1,-1}, // state 0
            {-1, 8,-1, 7,-1,-1}, // state 0
            {-1, 8,-1,-1,-1,-1}, // state 0
        };

        int state, cnt, size;
        state = cnt = 0;
        size = s.size();
        while(cnt < size) {
            auto input = INVALID;
            if(isspace(s[cnt])) input = SPACE;
            else if(s[cnt] == '+' || s[cnt] == '-') input = SIGNAL;
            else if(s[cnt] <= '9' && s[cnt] >= '0') input = DIGITAL;
            else if(s[cnt] == '.') input = DOT;
            else if(s[cnt] == 'e' || s[cnt] == 'E') input = EXPO;

            state = transition_table[state][input];

            if(state == -1) return false;
            else ++cnt;
        }

        return state == 1 || state == 4 || state == 7 || state == 8; 
    }
};

int main() {
    vs test {"0", " 0.1 ", "10023.0", "abc", "1 a", "20e-01", "e9"};

    Solution sol;

    for(auto &c : test)
        cout << (sol.isNumber(c) ? "true" : "false") << endl;

    return 0;
}
