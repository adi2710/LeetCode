class Solution {
public:
    
    int solve(int i, int k, vector<vector<int>> &piles, vector<vector<int>> &dp)
    {
        if(i == piles.size())
            return 0;
        if(dp[i][k] != -1)
            return dp[i][k];
        int ans = solve(i + 1, k, piles, dp), sum = 0;
        for(int j = 0; j < piles[i].size() && j < k; j++){
            sum += piles[i][j];
            ans = max(ans, sum + solve(i + 1, k - j - 1, piles, dp));
        }
        return dp[i][k] = ans;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size(), vector<int> (k + 1, -1));
        return solve(0, k, piles, dp);
    }
};