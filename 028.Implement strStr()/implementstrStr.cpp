#include <iostream>
#include <cstring>
using namespace std;

void printMatchTable(int table[], int size); 

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int pattern_len = strlen(needle);
        int string_len = strlen(haystack);
        if(pattern_len > string_len) return -1;
        int* match_table = new int[pattern_len + 1];
        genMatchTable(needle, match_table);

        int cnt = 0;
        while(cnt + pattern_len <= string_len) {
            int pattern_cnt = 0;
            while(cnt < string_len && pattern_cnt < pattern_len && haystack[cnt] == needle[pattern_cnt]) {
                ++cnt, ++pattern_cnt;
            }
            if(pattern_cnt == pattern_len) return (cnt - pattern_len);
            cnt -= match_table[pattern_cnt];
        } 
        return -1;
    }

    void genMatchTable(char *A, int table[]) {
        if(A[0] == 0) return;
        table[0] = -1;
        table[1] = 0;
        int cnt = 1;
        while(A[cnt] != 0) {
            int iter = 0;
            while(A[cnt] != 0 && A[cnt] == A[iter]) {
                table[cnt + 1] = table[cnt] + 1;
                ++cnt, ++iter;
            }
            if(A[cnt] != 0) {
                table[cnt + 1] = 0;
                ++cnt;
            }
        }
    }
};

void printMatchTable(int table[], int size) {
    for(int i = 0; i < size; ++i) {
        cout << table[i] << ' ';
    }
    cout << endl;
}

int main() {
    char haystack[] = "";
    char needle[] = "";
    Solution sol;
    cout << sol.strStr(haystack, needle) << endl;
    return 0;
}
