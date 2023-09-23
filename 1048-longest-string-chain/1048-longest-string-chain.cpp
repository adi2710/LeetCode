class Solution {
public:
    
    bool checkSubsequence(string &a, string &b)
    {
        if(a.size() + 1 != b.size())
            return false;
        
        for(int i = 0, j = 0, cnt = 0; i < b.size() && j < a.size(); i++, j++)
        {
            if(a[j] != b[i])
                cnt++, j--;
            if(cnt == 2)
                return false;
        }
        return true;
    }
    
    int solve(int i, int prev, vector<string> &words, vector<vector<int>> &dp)
    {
        if(i == words.size())
            return 0;
        
        if(dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        
        int take = 0, skip = 0;
        if(prev == -1 || checkSubsequence(words[prev], words[i]))
            take = 1 + solve(i + 1, i, words, dp);
        
        skip = solve(i + 1, prev, words, dp);
        return dp[i][prev + 1] = max(take, skip);
    }
    
    int longestStrChain(vector<string>& words) {
        vector<vector<int>> dp(words.size(), vector<int> (words.size() + 1, -1));
        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.size() < b.size();
        });
        return solve(0, -1, words, dp);
    }
};