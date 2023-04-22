class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        vector<int> new_dp(n + 1);
        for(int i = 1; i <= n; i++)
        {
            new_dp[0] = 0;
            for(int j = 1; j <= n; j++)
            {
                if(s[i - 1] == s[n - j])
                    new_dp[j] = dp[j - 1] + 1;
                else
                    new_dp[j] = max(new_dp[j - 1], dp[j]);
            }
            dp = new_dp;
        }
        return n - dp[n];
    }
};