#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int, int> > vpii;
typedef unordered_map<int, vpii> MAP;

void printVI(vi &t);
void printVVI(vvi & t);

class Solution {
public:
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef vector<pair<int, int> > vpii;
    typedef unordered_map<int, vpii> MAP;
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        return fourSum_method2(num, target);
    }

    vvi fourSum_method2(vi &num, int target) {
        if(num.size() < 4) return vvi{}; 
        sort(num.begin(), num.end());

        MAP map;
        vvi ret;
        for(int i = 0; i < num.size() - 1; ++i) {
            for(int j = i + 1; j < num.size(); ++j) {
                map[num[i] + num[j]].push_back(make_pair(i, j)); 
            }
        }

        for(auto it = num.begin(); it != num.end() - 3; ++it) {
            if(it != num.begin() && *it == *(it - 1)) continue;
            for(auto it2 = it + 1; it2 != num.end() - 2; ++it2) {
                if(it2 != it + 1 && *it2 == *(it2 - 1)) continue;
                int temp = target - *it - *it2;
                auto kv = map.find(temp);
                if(kv == map.end()) {
                    continue;
                }
                auto array = kv->second;
                int dis = distance(num.begin(), it2);
                for(auto &pair : array) {
                    if(pair.first > dis && pair.second > dis) {
                        vi temp {*it, *it2, num[pair.first], num[pair.second]};
                        if(ret.empty() || ret.back() != temp)
                            ret.push_back(temp);
                    }
                }
            }
        }
        return ret;
    }
};

void printVI(vi &t) {
    cout << "Printing vi" << endl;
    for(vi::iterator it2 = t.begin(); it2 < t.end(); ++it2) {
        cout << *it2 << ' ';
    }
    cout << endl;
}

void printVVI(vvi & t) {
    for(vvi::iterator it = t.begin(); it < t.end(); ++it) {
        for(vi::iterator it2 = it->begin(); it2 < it->end(); ++it2) {
            cout << *it2 << ' ';
        }
        cout << endl;
    }
}

int main() {
    Solution sol;
    vi test {1, 0, -1, 0, -2, 2};
    int target = 0;
    vvi result = sol.fourSum(test, target);
    printVVI(result);
    return 0;
}
/*vi trim(vpii::iterator &it1, vpii::iterator &it2) {
    vi temp;
    temp.push_back(it1->first); 
    temp.push_back(it1->second); 
    temp.push_back(it2->first); 
    temp.push_back(it2->second); 
    sort(temp.begin(), temp.end());
    auto last = unique(temp.begin(), temp.end());   
    temp.erase(last, temp.end());
    return temp;
}

vector<vector<int> > fourSum_method1(vector<int> &num, int target) {
    svi ret;
    vi temp;
    vi ret_four;
    MAP map;
    if(num.size() < 4) return vvi{};

    this->m_nums = num;
    for(int i = 0; i < num.size() - 1; ++i) {
        for(int j = i + 1; j < num.size(); ++j) {
            map[num[i] + num[j]].push_back(make_pair(i, j));
        }
    } 

    for(MAP::iterator it = map.begin(); it != map.end(); ++it) {
        auto it2 = map.find(target - it->first);
        if(it2 == map.end()) {
            continue;
        }
        if(2 * it2->first == target) {
            if(it2->second.size() == 1) {
                continue;
            }
            else {
                auto &t = it2->second;
                for(auto i = t.begin(); i < t.end() - 1; ++i)
                    for(auto j = i + 1; j < t.end(); ++j)
                        if((temp = trim(i, j)).size() == 4) {
                            ret_four.clear();
                            for(auto index : temp)
                                ret_four.push_back(m_nums[index]);
                            sort(ret_four.begin(), ret_four.end());
                            ret.insert(ret_four);
                        }
            }
        }
        else {
            auto &l1 = it->second;
            auto &l2 = it2->second;
            for(auto i = l1.begin(); i != l1.end(); ++i)
                for(auto j = l2.begin(); j != l2.end(); ++j)
                    if((temp = trim(i, j)).size() == 4) {
                        ret_four.clear();
                        for(auto index : temp)
                            ret_four.push_back(m_nums[index]);
                        sort(ret_four.begin(), ret_four.end());
                        ret.insert(ret_four);
                    }
        }
    }
    return vvi{ret.begin(), ret.end()};
}
private:
vi m_nums;
*/
