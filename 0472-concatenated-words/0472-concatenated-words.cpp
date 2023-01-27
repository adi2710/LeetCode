class Solution {
public:
    
    bool isConcatenated(int i, string &word, vector<int> &dp, unordered_set<string> &st)
    {
        if(i == word.size())
            return true;
        
        if(dp[i] != -1)
            return dp[i];
        
        string s;
        bool fl = false;
        for(int j = i; j < word.size(); j++)
        {
            s += word[j];
            if(st.find(s) != st.end())
                fl = fl || isConcatenated(j + 1, word, dp, st);
        }
        return dp[i] = fl;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.size() < b.size();
        });
        vector<string> ans;
        unordered_set<string> st;
        for(string &word : words)
        {
            vector<int> dp(word.size(), -1);
            if(isConcatenated(0, word, dp, st))
                ans.push_back(word);
            st.insert(word);
        }
        return ans;
    }
};