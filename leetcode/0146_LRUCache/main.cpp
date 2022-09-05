#include <unordered_map>
#include <list>

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        return getVal(key);
    }

    void put(int key, int value) {
        insertKeyVal(key, value);
    }

private:
    int capacity = 0;
    std::list<std::pair<int, int>> cacheList;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;

    int getVal(int key) {
        auto cacheMapIt = this->cacheMap.find(key);
        if(cacheMapIt != this->cacheMap.end()) {
            this->cacheList.splice(this->cacheList.begin(), this->cacheList, cacheMapIt->second);
            return cacheMapIt->second->second;
        }
        else
            return -1;
    }

    void insertKeyVal(int key, int value) {
        auto cacheMapIt = this->cacheMap.find(key);
        if(cacheMapIt != this->cacheMap.end())
            this->cacheList.erase(cacheMapIt->second);

        std::list<std::pair<int, int>>::iterator tmp = this->cacheList.insert(this->cacheList.begin(),std::pair<int, int>(key, value));
        this->cacheMap[key] = tmp;

        if(this->cacheMap.size() > this->capacity) {
            int lastKey = this->cacheList.back().first;
            cacheList.pop_back();
            this->cacheMap.erase(lastKey);
        }
    }

};


int main(int argc, char** argv) {
    LRUCache sol = LRUCache(3);
    sol.put(1,1);
    sol.put(2,2);
    sol.put(1,10);
    sol.put(3,3);
    sol.put(4,4);
    sol.get(1);
    return 0;

}
