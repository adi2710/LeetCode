class Solution {
public:
    
    int dp[5000][2];
    int solve(int i, bool hold, vector<int> &prices)
    {
        if(i >= prices.size())
            return 0;
        
        if(dp[i][hold] != -1)
            return dp[i][hold];
        
        if(hold)
            return dp[i][hold] = max(solve(i + 2, 0, prices) + prices[i], solve(i + 1, 1, prices));
        else
            return dp[i][hold] = max(solve(i + 1, 1, prices) - prices[i], solve(i + 1, 0, prices));
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, prices);
    }
};