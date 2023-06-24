class Solution {
public:
    
    int solve(int i, char st, char en, vector<string> &words, vector<vector<vector<int>>> &dp)
    {
        if(i == words.size())
            return 0;
        if(dp[i][st - 'a'][en - 'a'] != -1)
            return dp[i][st - 'a'][en - 'a'];
        int n1 = (en == words[i].front() ? 1 : 0) + solve(i + 1, st, words[i].back(), words, dp);
        int n2 = (words[i].back() == st ? 1 : 0) + solve(i + 1, words[i].front(), en, words, dp);
        return dp[i][st - 'a'][en - 'a'] = max(n1, n2);
    }
    
    int minimizeConcatenatedLength(vector<string>& words) {
        int sz = 0;
        for(string &word : words)
            sz += word.size();
        vector<vector<vector<int>>> dp(words.size(), vector<vector<int>> (26, vector<int> (26, -1)));
        return sz - solve(1, words[0].front(), words[0].back(), words, dp);
    }
};