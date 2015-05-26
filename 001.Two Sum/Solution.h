#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
    using vi = vector<int>;
    using pii = pair<int, int>;
    using vpii = vector<pii>;
    using MAP = unordered_map<int, vi>;
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        return twoSum2(numbers, target);
    }

    vi twoSum1(vi &numbers, int target)
    {
        int size = numbers.size();
        vpii vec_numbers;
        for(int i = 0; i != size; ++i)
            vec_numbers.push_back(make_pair(numbers[i], i + 1));

        sort(vec_numbers.begin(), vec_numbers.end(), \
                [](const pii &a, const pii &b) { return a.first < b.first; });

        int l = 0, r = size - 1;
        while(l < r)
        {
            int t = vec_numbers[l].first + vec_numbers[r].first;
            if(t == target) break;
            if(t < target) ++l;
            else --r;
        }

        vi ret;
        ret.push_back(min(vec_numbers[l].second, vec_numbers[r].second));
        ret.push_back(max(vec_numbers[l].second, vec_numbers[r].second));
        return ret;
    }

    vi twoSum2(vi& numbers, int target)
    {
        MAP map;
        vi ret;
        int size = numbers.size();
        for(int i = 0; i != size; ++i)
            map[numbers[i]].push_back(i + 1);

        for(int i = 0; i != size; ++i)
        {
            MAP::iterator it = map.find(target - numbers[i]);
            if(it == map.end()) continue;

            int index1 = it->second[0], index2 = i + 1;
            if(numbers[i] == target - numbers[i])
            {
                if(map[numbers[i]].size() == 1) continue;
                index2 = it->second[1];
            }

            ret.push_back(min(index1, index2));
            ret.push_back(max(index1, index2));
            return ret;
        }
        return ret;
    }
};
