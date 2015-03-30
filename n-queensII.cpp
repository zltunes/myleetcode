#include <iostream>
#include <vector>
using namespace std;

class Solution {
    using vi = vector<int>;
public:
    int totalNQueens(int n) {
        vector<int> temp;
        for(int i = 0; i < n; ++i) {
            temp.push_back(i);
        }
        int ans = 0;
        while(next_permutation(temp.begin(), temp.end())) {
            int this_turn = 1;
            for(auto it = temp.begin(); it < temp.end(); ++it)
                if(count_if(temp.begin(), it, [=](vi::iterator n) { return it - n == *it - *n || it - n == *n - *it; })) {
                    this_turn = 0;
                    break;
                }
            ans += this_turn;
        }
        return ans;
    }
    /*int totalNQueens(int n) {
      if(count == -1) {
      max_size = n;
      count = 0;
      }
      if(n == 0) ++count;
      for(int i = 0; i < max_size; ++i) {
      if(!isValid(i)) continue;
      table.insert(table.begin(), i);
      totalNQueens(n - 1);
      table.erase(table.begin());
      }
      return count;
      }
      bool isValid(int col) {
      for(int i = 0; i < table.size(); ++i) {
      if(table[i] == col) return false;
      if(i + 1 == abs(table[i] - col)) return false;
      }
      return true;
      }*/
    /*private:
      vi table;
      int max_size = 0;
      int count = -1;*/
};

int main() {
    Solution sol;
    cout << sol.totalNQueens(8) << endl;
    return 0;
}
