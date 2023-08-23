#include "includes/universal.h"
using namespace std;

template<typename K, typename V>
class LRU {
private:
    using DLL = list<pair<K, V>>;
    using DLLI = DLL::iterator;
    using HashMap = unordered_map<K, DLLI>;
    using HMI = HashMap::iterator;

    const int maxSize;
    HashMap cache;
    DLL dll;
    int curSize;

public:
    LRU(int maxSize): maxSize(maxSize), cache(), dll(), curSize(0) {}

    // optional is C++17 or later
    optional<V> get(const K &key) {
        HMI itElem = cache.find(key);
        if (itElem == cache.end()) {
            return {};
        }
        DLLI it = itElem -> second;
        pair<K, V> p = *it;
        dll.erase(it);
        dll.push_front(p);
        return p.second;
    }

    void set(const K &key, const V &value) {
        HMI itElem = cache.find(key);
        if (curSize >= maxSize) {
            if (itElem != cache.end()) {
                DLLI it = itElem -> second;
                dll.erase(it);
            } else {
                cache.erase(dll.back().first);
                dll.pop_back();
            }
            curSize--;
        }
        pair<K, V> p(key, value);
        dll.push_front(p);
        cache[key] = dll.begin();
        curSize++;
        return ;
    }

    void debug() const {
        cout << dll << endl;
    }
};

int main() {
    LRU<int, string> lru(5);
    lru.debug();
    lru.set(1, "A");
    lru.debug();
    lru.set(2, "B");
    lru.debug();
    lru.set(3, "C");
    lru.debug();
    lru.set(4, "D");
    lru.debug();
    lru.set(5, "E");
    lru.debug();
    lru.set(6, "F");
    lru.debug();
    lru.set(1, "A2");
    lru.debug();
    lru.set(1, "A3");
    lru.debug();
    cout << *lru.get(5) << endl;
    lru.debug();
    return 0;
}
