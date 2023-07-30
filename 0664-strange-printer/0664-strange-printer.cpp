class Solution {
public:
    
    int solve(int l, int r, string &s, vector<vector<int>> &dp)
    {
        if(dp[l][r] != -1)
            return dp[l][r];
        int ans = s.size(), j = -1;
        for(int i = l; i < r; i++)
        {
            if(s[i] != s[r] && j == -1)
                j = i;
            if(j != -1)
                ans = min(ans, 1 + solve(j, i, s, dp) + solve(i + 1, r, s, dp));
        }
        if(j == -1)
            ans = 0;
        return dp[l][r] = ans;
    }
    
    int strangePrinter(string s) {
        vector<vector<int>> dp(s.size(), vector<int> (s.size(), -1));
        return 1 + solve(0, s.size() - 1, s, dp);
    }
};