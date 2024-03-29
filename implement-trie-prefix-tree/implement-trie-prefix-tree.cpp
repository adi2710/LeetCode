class Trie {
public:
    
    struct trie{
        bool isTerminal;
        vector<trie*> child;
        trie(){
            isTerminal = false;
            child.resize(26, nullptr);
        }
    };
    
    trie *node;
    Trie() {
        node = new trie();
    }
    
    void insert(string word) {
        trie* cur = node;
        for(char ch : word)
        {
            if(cur -> child[ch - 'a'] == nullptr)
                cur -> child[ch - 'a'] = new trie();
            cur = cur -> child[ch - 'a'];
        }
        cur -> isTerminal = true;
    }
    
    bool search(string word) {
        trie* cur = node;
        for(char ch : word)
        {
            if(cur -> child[ch - 'a'] == nullptr)
                return false;
            cur = cur -> child[ch - 'a'];
        }
        return cur -> isTerminal;
    }
    
    bool startsWith(string prefix) {
        trie* cur = node;
        for(char ch : prefix)
        {
            if(cur -> child[ch - 'a'] == nullptr)
                return false;
            cur = cur -> child[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */