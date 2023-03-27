class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m), new_dp(m);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0)
                    new_dp[j] = grid[i][j];
                else if(i == 0)
                    new_dp[j] = new_dp[j - 1] + grid[i][j];
                else if(j == 0)
                    new_dp[j] = dp[j] + grid[i][j];
                else
                    new_dp[j] = min(new_dp[j - 1], dp[j]) + grid[i][j];
            }
            dp = new_dp;
        }
        return dp[m - 1];
    }
};