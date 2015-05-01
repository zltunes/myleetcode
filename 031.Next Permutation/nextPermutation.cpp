#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printVec(vector<int> & vec) {
    for(auto item : vec)
        cout << item << " ";
    cout << endl;
}

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.empty() || num.size() == 1) return;
        int size = num.size();
        int cnt = size - 1;
        while(--cnt != -1) {
            if(num[cnt] < num[cnt + 1]) 
                break;
        }
        if(cnt != -1) {
            int minInMax = size - 1;
            for(; minInMax >= 0; --minInMax) {
                if(num[minInMax] > num[cnt]) break;
            }
            swap(num[cnt], num[minInMax]);
        }
        reverse(num, cnt + 1, size - 1);
    }
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void reverse(vector<int> &vec, int start, int end) {
        while(start <= end) {
            swap(vec[start], vec[end]);        
            ++start;
            --end;
        }
    }
};

int main() {
    vector<int> vec = {2,1,1};
    vector<int> test = {2,1,1};
    Solution sol;
    cout << "my algorithm" << endl;
    printVec(vec);
    sol.nextPermutation(vec);
    printVec(vec);

    cout << "stl algorithm" << endl;
    printVec(test);
    next_permutation(test.begin(), test.end());
    printVec(test);
    return 0;
}
