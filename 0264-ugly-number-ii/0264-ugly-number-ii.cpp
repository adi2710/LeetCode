class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for(int i = 2, j = 1, k = 1, l = 1; i <= n; i++)
        {
            dp[i] = min({dp[j] * 2, dp[k] * 3, dp[l] * 5});
            if(dp[i] == dp[j] * 2)
                j++;
            if(dp[i] == dp[k] * 3)
                k++;
            if(dp[i] == dp[l] * 5)
                l++;
        }
        return dp[n];
    }
};