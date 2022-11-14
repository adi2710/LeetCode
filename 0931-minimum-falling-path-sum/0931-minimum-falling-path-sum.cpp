class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> dp = matrix[0], new_dp(m);
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                new_dp[j] = dp[j];
                if(j - 1 >= 0)
                    new_dp[j] = min(new_dp[j], dp[j - 1]);
                if(j + 1 < m)
                    new_dp[j] = min(new_dp[j], dp[j + 1]);
                new_dp[j] += matrix[i][j];
            }
            dp = new_dp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};