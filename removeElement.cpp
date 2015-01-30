#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n == 0) return n;
        vector<int> pos;
        for(int i = 0; i < n; ++i) {
            if(elem == A[i])
                pos.push_back(i);
        }

        if(pos.empty()) return n;
        pos.push_back(n);
        for(auto i = 1; i < pos.size(); ++i) {
            for(auto iter = pos[i - 1] + 1; iter < pos[i]; ++iter) {
                A[iter - i] = A[iter];
            }
        }
        return n - pos.size() + 1;
    }
};

const int SIZE_INT = sizeof(int);

void printArray(int A[], int num) {
    for(int i = 0; i < num; ++i) {
        cout << A[i] << ' ';
    }
    cout << endl;
}

int main() {
    int test[] = {11};
    Solution sol;
    int len = sol.removeElement(test, sizeof(test) / SIZE_INT, 11);
    printArray(test, len);
    return 0;
}
