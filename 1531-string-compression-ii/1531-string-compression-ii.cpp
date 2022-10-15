class Solution {
public:
    
    int solve(int left, int K, string &s, vector<vector<int>> &dp)
    {
        if(s.size() - left <= K)
            return 0;
        if(dp[left][K] != -1)
            return dp[left][K];
        int ans = K ? solve(left + 1, K - 1, s, dp) : 1e5, k = K, cnt = 1;
        for(int i = left + 1; i <= s.size(); i++)
        {
            ans = min(ans, solve(i, k, s, dp) + 1 + (cnt >= 100 ? 3 : cnt >= 10 ? 2 : cnt >= 2 ? 1 : 0));
            if(i == s.size()) break;
            if(s[i] == s[left]) cnt++;
            else if(--k < 0) break;
        }
        return dp[left][K] = ans;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        vector<vector<int>> dp(s.size() + 1, vector<int> (k + 1, -1));
        return solve(0, k, s, dp);
    }
};