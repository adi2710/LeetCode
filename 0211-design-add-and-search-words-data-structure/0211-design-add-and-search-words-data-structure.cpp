struct Trie{
    vector<Trie*> child;
    bool isEnd;
    
    Trie()
    {
        child.resize(26, nullptr);
        isEnd = false;
    }
    
    void insertWord(string &word)
    {
        Trie *cur = this;
        for(char ch : word)
        {
            if(cur -> child[ch - 'a'] == nullptr)
                cur -> child[ch - 'a'] = new Trie();
            cur = cur -> child[ch - 'a'];
        }
        cur -> isEnd = true;
    }
    
    bool searchWord(Trie *cur, string &word, int pos = 0)
    {
        if(pos == word.size())
            return cur -> isEnd;
        
        if(word[pos] == '.')
        {
            bool fl = false;
            for(int i = 0; i < 26; i++)
            {
                if(cur -> child[i] != nullptr)
                    fl = fl || searchWord(cur -> child[i], word, pos + 1);
            }
            return fl;
        }
        
        if(cur -> child[word[pos] - 'a'] == nullptr)
            return false;
        return searchWord(cur -> child[word[pos] - 'a'], word, pos + 1);
    }
};

class WordDictionary {
public:
    Trie *trie;
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        trie -> insertWord(word);
    }
    
    bool search(string word) {
        return trie -> searchWord(trie, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */