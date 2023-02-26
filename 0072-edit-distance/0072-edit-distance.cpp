class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp(word2.size() + 1);
        iota(dp.begin(), dp.end(), 0);
        for(int i = 1; i <= word1.size(); i++)
        {
            vector<int> new_dp(word2.size() + 1);
            new_dp[0] = i;
            for(int j = 1; j <= word2.size(); j++)
            {
                if(word1[i - 1] != word2[j - 1])
                    new_dp[j] = 1 + min({dp[j - 1], dp[j], new_dp[j - 1]});
                else
                    new_dp[j] = dp[j - 1];
            }
            dp = new_dp;
        }
        return dp[word2.size()];
    }
};