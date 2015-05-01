#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        if(n == 0) return;
        int cnt_0 = 0;
        int cnt_2 = n - 1;
        for(int i = 0; i < n; ++i) {
            if(A[i] == 1) continue;
            if(A[i] == 0) {
                while(A[cnt_0] == 0) ++cnt_0;
                if(cnt_0 < i) {
                    swap(A[cnt_0], A[i]);
                    --i;
                }
            }
            else {
                while(A[cnt_2] == 2) --cnt_2;
                if(cnt_2 > i) {
                    swap(A[cnt_2], A[i]);
                    --i;
                }
            }
        }
    }
};

int* genArray(int n) {
    int *ret = new int[n];
    for(int i = 0; i < n; ++i) {
        ret[i] = rand() % 3;
    }
    return ret;
}

void printArray(int A[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << A[i] << ' ';
    }
    cout << endl;
}

int main() {
    srand(time(0));
    int array_size = 100;
    int *array = genArray(array_size);
    printArray(array, array_size);

    Solution sol;
    sol.sortColors(array, array_size);
    printArray(array, array_size);

    return 0;
}
