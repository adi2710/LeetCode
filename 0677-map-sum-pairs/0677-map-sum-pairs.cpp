class Trie{
public:
    
    bool isEnd;
    int valSum;
    vector<Trie*> child;
    
    Trie()
    {
        isEnd = false;
        valSum = 0;
        child.resize(26, nullptr);
    }
    
    void insert(string &s, int val, int prev)
    {
        Trie *cur = this;
        for(char ch : s)
        {
            if(cur -> child[ch - 'a'] == nullptr)
                cur -> child[ch - 'a'] = new Trie();
            cur -> valSum += val - prev;
            cur = cur -> child[ch - 'a'];
        }
        cur -> valSum += val - prev;
        cur -> isEnd = true;
    }
    
    int findPrefix(string &s)
    {
        Trie *cur = this;
        for(char ch : s)
        {
            if(cur -> child[ch - 'a'] == nullptr)
                return 0;
            cur = cur -> child[ch - 'a'];
        }
        return cur -> valSum;
    }
};

class MapSum {
public:
    Trie *trie;
    unordered_map<string, int> preVal;
    MapSum() {
        trie = new Trie();
    }
    
    void insert(string key, int val) {
        trie -> insert(key, val, preVal[key]);
        preVal[key] = val;
    }
    
    int sum(string prefix) {
        return trie -> findPrefix(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */