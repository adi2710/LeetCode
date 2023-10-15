class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int i, int steps, int arrLen, vector<vector<int>> &dp){
        if(steps == 0)
            return i == 0 ? 1 : 0;
        if(dp[i][steps] != -1)
            return dp[i][steps];
        int left = 0, right = 0, stay = solve(i, steps - 1, arrLen, dp);
        if(i - 1 >= 0)
            left = solve(i - 1, steps - 1, arrLen, dp);
        if(i + 1 < arrLen)
            right = solve(i + 1, steps - 1, arrLen, dp);
        return dp[i][steps] = (1ll * stay + left + right) % MOD;
    }
    
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps + 1, vector<int> (steps + 1, -1));
        return solve(0, steps, arrLen, dp);
    }
};