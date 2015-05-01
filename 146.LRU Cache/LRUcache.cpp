#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache{
public:
    struct LRUNode {
        int k, v;
    };
    LRUCache(int capacity) {
       this->size = capacity;
    }

    int get(int key) {
        if(cache_map.find(key) != cache_map.end()) {
            auto it = cache_map[key];
            cache_list.splice(cache_list.begin(), cache_list, it);
            cache_map[key] = cache_list.begin();
            return cache_list.begin()->v;
        }
        return -1;
    }

    void set(int key, int value) {
        if(cache_map.find(key) == cache_map.end()) {
            if(cache_list.size() == size) {
                cache_map.erase(cache_list.back().k);
                cache_list.pop_back();
            }
            cache_list.push_front(LRUNode {key, value});
            cache_map[key] = cache_list.begin(); 
        }
        else {
            auto it = cache_map[key];
            cache_list.splice(cache_list.begin(), cache_list, it);
            cache_list.front().v = value;
            cache_map[key] = cache_list.begin();
        }
    }
private:
    int size;
    list<LRUNode> cache_list;
    unordered_map<int, list<LRUNode>::iterator > cache_map;
};

int main() {
    
    LRUCache cache(2);
    cache.set(1,20);
    cache.set(4,20);
    cout << cache.get(4) << endl;
    cache.set(5,20);
    cout << cache.get(1) << endl;
    cout << cache.get(4) << endl;
    cout << cache.get(5) << endl;
    cache.set(7,20);
    cout << cache.get(4) << endl;

    return 0;
}
