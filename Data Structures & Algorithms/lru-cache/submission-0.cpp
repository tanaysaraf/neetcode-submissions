class LRUCache {
public:
    map<int, int> kv;
    list<int> cache;
    map<int, list<int>::iterator> mp; // key -> position in cache
    int cap = 0;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (kv.find(key) == kv.end()) return -1;

        auto pos = mp[key];

        cache.erase(pos);
        cache.push_front(key);
        mp[key] = cache.begin();

        return kv[key];
    }

    void put(int key, int value) {
        if (cap == 0) return;

        // If key already exists, update value and move to front
        if (kv.find(key) != kv.end()) {
            kv[key] = value;

            auto pos = mp[key];
            cache.erase(pos);
            cache.push_front(key);
            mp[key] = cache.begin();

            return;
        }

        if (cache.size() < cap) {
            cache.push_front(key);
            kv[key] = value;
            mp[key] = cache.begin();
        }
        else {
            int last = cache.back();
            cache.pop_back();

            kv.erase(last);
            mp.erase(last);

            cache.push_front(key);
            kv[key] = value;
            mp[key] = cache.begin();
        }
    }
};