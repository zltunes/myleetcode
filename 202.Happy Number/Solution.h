#include <unordered_set>

class Solution {
    using usi = std::unordered_set<int>;
public:
    bool isHappy(int n)
    {
        usi check_table;
        do {
            check_table.insert(n);
            if(n == 1)
            {
                return true;
            }
            n = getNext(n);
        } while(check_table.count(n) == 0);
        return false;
    }

    int getNext(int n)
    {
        int sum = 0;
        while(n)
        {
            int t = n % 10;
            sum += t * t;
            n /= 10;
        }
        return sum;
    }
};
