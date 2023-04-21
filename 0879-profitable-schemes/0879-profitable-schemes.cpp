class Solution {
public:
    
    const int MOD = 1e9 + 7;
    int dp[101][101][101];
    
    int solve(int i, int curProfit, int n, int &minProfit, vector<int> &group, vector<int> &profit)
    {
        if(n < 0)
            return 0;
        if(i == profit.size())
            return curProfit >= minProfit;
        if(dp[i][curProfit][n] != -1)
            return dp[i][curProfit][n];
        int sum = (1ll * solve(i + 1, min(minProfit, curProfit + profit[i]), n - group[i], minProfit, group, profit) + solve(i + 1, curProfit, n, minProfit, group, profit)) % MOD;
        return dp[i][curProfit][n] = sum;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, n, minProfit, group, profit);
    }
};