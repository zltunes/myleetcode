#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) {
        this->size = 0;
        this->capacity = capacity;
    }

    int get(int key) {
        if(cacheMap.count(key) == 0) return -1;
        for(map<int, int> :: iterator it = cacheMap.begin(); it != cacheMap.end(); ++it) {
            it->second += 1;
        }
        cacheMap[key] = 0;
        return storeMap[key];
    }

    void set(int key, int value) {
        storeMap[key] = value;
        if(cacheMap.count(key) == 0) {
            if(size < capacity) {
                size++;
            }
            else {
                int LUU = 0, LUUkey = 0;
                for(map<int, int> :: iterator it = cacheMap.begin(); it != cacheMap.end(); ++it) {
                    if(it->second > LUU) { 
                        LUU = it->second;
                        LUUkey = it->first; 
                    }
                }
                cacheMap.erase(LUUkey);
            }
        }
        cacheMap[key] = 0;
    }
private:
    int size;
    int capacity;
    unordered_map<int, int> storeMap;
    map<int,int> cacheMap;
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
