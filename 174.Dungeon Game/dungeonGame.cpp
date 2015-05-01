#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int height = dungeon.size(), width = dungeon[0].size();
        int cur = dungeon.back().back();
        dungeon[height - 1][width - 1] = cur >= 0 ? 1 : abs(cur) + 1;

        for(int i = width - 2; i >= 0; --i) {
            int &cur = dungeon[height - 1][i];
            if(cur >= 0) {
                if(cur >= dungeon[height - 1][i + 1])
                    cur = 1;
                else
                    cur = dungeon[height - 1][i + 1] - cur; 
            }
            else {
                cur = dungeon[height - 1][i + 1] - cur;
            }
        }

        for(int i = height - 2; i >= 0; --i) {
            int &cur = dungeon[i][width - 1];
            if(cur >= 0) {
                if(cur >= dungeon[i + 1][width - 1])
                    cur = 1;
                else
                    cur = dungeon[i + 1][width - 1] - cur; 
            }
            else {
                cur = dungeon[i + 1][width - 1] - cur;
            }
        }

        for(int i = height - 2; i >= 0; --i) {
            for(int j = width - 2; j >= 0; --j) {
                int min_need = min(dungeon[i + 1][j], dungeon[i][j + 1]);
                int &cur = dungeon[i][j];
                if(cur >= 0) {
                    if(cur >= min_need)
                        cur = 1;
                    else
                        cur = min_need - cur;
                }
                else {
                    cur = min_need - cur;
                }
            } 
        } 

        /*for(auto &row : dungeon) {
            for(auto &item : row)
                cout << item << ' ';
            cout << endl;
        }*/
        return dungeon[0][0];
    }
};

int main() {
    vvi dungeon {
        {-3},
        {-7},
    };

    Solution sol;
    cout << sol.calculateMinimumHP(dungeon) << endl;
    return 0;
}
