class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> mp = {{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}, {0, 1, 2, 3, 4}};
    
    int solve(int cur, int n, vector<vector<int>> &dp)
    {
        if(n == 0)
            return 1;
        
        if(dp[cur][n] != -1)
            return dp[cur][n];
        
        int ans = 0;
        for(int next : mp[cur])
            ans = (1ll * ans + solve(next, n - 1, dp)) % MOD;
        return dp[cur][n] = ans;
    }
    
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(6, vector<int> (n + 1, -1));
        return solve(5, n, dp);
    }
};