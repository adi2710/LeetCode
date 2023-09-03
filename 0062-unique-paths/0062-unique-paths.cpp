class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n);
        dp[0] = 1;
        for(int i = 0; i < m; i++)
        {
            vector<int> new_dp(n);
            new_dp[0] = 1;
            for(int j = 1; j < n; j++)
                new_dp[j] = dp[j] + new_dp[j - 1];
            dp = new_dp;
        }
        return dp[n - 1];
    }
};