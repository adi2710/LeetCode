class LFUCache {
public:
    unordered_map<int, list<pair<int, int>>> ls;
    unordered_map<int, pair<int, list<pair<int, int>> :: iterator>> freq;
    int sz, minFreq;
    LFUCache(int capacity) {
        ls.clear();
        freq.clear();
        sz = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(freq.find(key) == freq.end())
            return -1;
        auto it = freq[key].second;
        int val = (*it).second;
        put(key, val);
        return val;
    }
    
    void put(int key, int value) {
        if(freq.find(key) != freq.end())
        {
            auto it = freq[key].second;
            int fr = freq[key].first;
            ls[fr].erase(it);
            if(ls[fr].empty()){
                ls.erase(fr);
                if(minFreq == fr)
                    minFreq++;
            }
            ls[fr + 1].push_back({key, value});
            freq[key] = {fr + 1, --ls[fr + 1].end()};
            return;
        }
        if(freq.size() == sz && minFreq >= 1)
        {
            int key = ls[minFreq].front().first;
            freq.erase(key);
            ls[minFreq].erase(ls[minFreq].begin());
            if(ls[minFreq].empty())
                ls.erase(minFreq);
        }
        if(freq.size() < sz){
            ls[1].push_back({key, value});
            freq[key] = {1, --ls[1].end()};
            minFreq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */