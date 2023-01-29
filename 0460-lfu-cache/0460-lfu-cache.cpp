class LFUCache {
public:
    unordered_map<int, list<pair<int, int>>> lfu_cache;
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> key_map;
    int capacity, cur_size, min_freq;
    LFUCache(int capacity) {
        this -> capacity = capacity;
        cur_size = 0;
        min_freq = 0;
    }
    
    int get(int key) {
        if(key_map.find(key) == key_map.end())
            return -1;
        auto it = key_map[key].second;
        int freq = key_map[key].first, value = (*it).second;
        if(lfu_cache[freq].size() == 1)
        {
            if(min_freq == freq)
                min_freq++;
            lfu_cache.erase(freq);
        }
        else
            lfu_cache[freq].erase(it);
        lfu_cache[freq + 1].push_back({key, value});
        key_map[key] = {freq + 1, --(lfu_cache[freq + 1].end())};
        return value;
    }
    
    void put(int key, int value) {
        if(capacity == 0)
            return;
        if(key_map.find(key) == key_map.end())
        {
            if(cur_size == capacity)
            {
                auto it = lfu_cache[min_freq].begin();
                int lfu_key = (*it).first;
                lfu_cache[min_freq].erase(it);
                key_map.erase(lfu_key);
                if(lfu_cache[min_freq].empty())
                    lfu_cache.erase(min_freq);
                cur_size--;
            }
            lfu_cache[1].push_back({key, value});
            key_map[key] = {1, --(lfu_cache[1].end())};
            min_freq = 1;
            cur_size++;
        }
        else
        {
            auto it = key_map[key].second;
            (*it).second = value;
            get(key);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// 1- 3
// 2- 1