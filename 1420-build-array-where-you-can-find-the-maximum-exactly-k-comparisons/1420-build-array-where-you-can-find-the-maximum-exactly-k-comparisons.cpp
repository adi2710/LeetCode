class Solution {
public:
    
    const int MOD = 1e9 + 7;
    int solve(int i, int mx, int k, int &n, int &m, vector<vector<vector<int>>> &dp)
    {
        if(k < 0)
            return 0;
        
        if(i == n)
            return k == 0 ? 1 : 0;
        
        if(dp[i][mx][k] != -1)
            return dp[i][mx][k];
        
        int cnt = 0;
        for(int num = 1; num <= m; num++)
        {
            if(mx < num)
                cnt = (1ll * cnt + solve(i + 1, num, k - 1, n, m, dp)) % MOD;
            else
                cnt = (1ll * cnt + solve(i + 1, mx, k, n, m, dp)) % MOD;
        }
        return dp[i][mx][k] = cnt; 
    }
    
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m + 1, vector<int> (k + 1, -1)));
        return solve(0, 0, k, n, m, dp);
    }
};