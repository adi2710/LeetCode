class AllOne {
public:
    
    unordered_map<string, int> freq;
    unordered_map<int, unordered_set<string>> mp;
    int mxFreq, mnFreq;
    
    AllOne() {
        freq.clear();
        mp.clear();
        mxFreq = 0;
        mnFreq = 0;
    }
    
    void inc(string key) {
        if(freq.find(key) == freq.end())
        {
            mp[1].insert(key);
            freq[key] = 1;
            mnFreq = 1;
            mxFreq = max(mxFreq, 1);
            return;
        }
        int fr = freq[key];
        mp[fr].erase(key);
        if(mp[fr].empty()){
            mp.erase(fr);
            if(mnFreq == fr)
                mnFreq++;
        }
        mxFreq = max(mxFreq, fr + 1);
        freq[key] = fr + 1;
        mp[fr + 1].insert(key);
    }
    
    void dec(string key) {
        int fr = freq[key];
        freq.erase(key);
        mp[fr].erase(key);
        if(mp[fr].empty()){
            mp.erase(fr);
            if(mnFreq == fr)
                mnFreq--;
            if(mxFreq == fr)
                mxFreq--;
        }
        if(fr == 1){
            if(!freq.empty()){
                while(mp.find(mnFreq) == mp.end())
                    mnFreq++;
            }
            return;
        }
        freq[key] = fr - 1;
        mp[fr - 1].insert(key);
    }
    
    string getMaxKey() {
        if(mxFreq == 0)
            return "";
        return *mp[mxFreq].begin();
    }
    
    string getMinKey() {
        if(mnFreq == 0)
            return "";
        return *mp[mnFreq].begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */