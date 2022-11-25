class Trie{
public:
    bool isEnd;
    vector<Trie*> child;
    
    Trie()
    {
        isEnd = false;
        child.resize(26, nullptr);
    }
    
    void insert(string &s)
    {
        Trie *cur = this;
        for(char ch : s)
        {
            if(cur -> child[ch - 'a'] == nullptr)
                cur -> child[ch - 'a'] = new Trie();
            cur = cur -> child[ch - 'a'];
        }
        cur -> isEnd = true;
    }
    
    int findPrefix(string &s)
    {
        Trie *cur = this;
        for(int i = 0; i < s.size() && cur != nullptr; i++)
        {
            if(cur -> isEnd)
                return i;
            cur = cur -> child[s[i] - 'a'];
        }
        return s.size();
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie *trie = new Trie();
        for(string &dictWord : dictionary)
            trie -> insert(dictWord);
        stringstream ss(sentence);
        string word, ans;
        while(ss >> word)
        {
            int pos = trie -> findPrefix(word);
            ans += word.substr(0, pos) + " ";
        }
        ans.pop_back();
        return ans;
    }
};