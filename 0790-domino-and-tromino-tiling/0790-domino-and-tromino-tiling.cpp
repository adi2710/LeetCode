class Solution {
public:
    
    int dp[1001];
    int solve(int n)
    {
        if(n <= 1)
            return 1;
        if(n == 2)
            return 2;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = (2ll * solve(n - 1) + solve(n - 3)) % (int)(1e9 + 7);
    }
    
    int numTilings(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};