class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int i, int &zero, int &one, int &low, int &high, vector<int> &dp)
    {
        if(i > high)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int res = 0;
        if(i >= low)
            res = 1;
        res = (1ll * res + solve(i + zero, zero, one, low, high, dp) + solve(i + one, zero, one, low, high, dp)) % MOD;
        return dp[i] = res;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return solve(0, zero, one, low, high, dp);
    }
};