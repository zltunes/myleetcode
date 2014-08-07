#include <iostream>
#include <assert.h>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        string strMAX = "2147483647";
        string strMIN = "2147483648";
        if(str == NULL) return 0;
        int cnt = 0;
        bool isNegative = false;
        deque<int> q;
        while(str[cnt] == ' ') ++cnt;
        if(str[cnt] == '-' || str[cnt] == '+') {
            if(str[cnt] == '-')
                isNegative = true;
            ++cnt;
        }
        while(isLegal(str[cnt])) {
            q.push_back(str[cnt] - '0');
            ++cnt;
        }
        if(q.size() > 10) {
            return isNegative ? INT_MIN : INT_MAX;
        }
        else {
            if(q.size() == 10) {
                if(!isNegative && strcmp(q, strMAX) >= 0)
                    return INT_MAX;
                if(isNegative && strcmp(q, strMIN) >= 0)
                    return INT_MIN;
            }
            int sum = 0;
            while(!q.empty()) {
                int t = q.front();
                sum *= 10;
                sum += t;
                q.pop_front();
            }
            return isNegative ? -sum : sum;
        }

    }
    int strcmp(deque<int> q, string str) {
        assert(q.size() == str.length());
        int cnt = 0;
        for(auto num : q) {
            if(num > str[cnt] - '0') return 1;
            if(num < str[cnt] - '0') return -1;
            ++cnt;
        }
        return 0;
    }
    bool isLegal(char chr) {
        if(chr >= '0' && chr <= '9') return true;
        return false;
    }
};

int main() {
    const char *num = "  +2147483646";
    Solution sol;
    cout << sol.atoi(num);

    return 0;
}
