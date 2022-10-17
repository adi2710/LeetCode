class Solution {
public:
    
    int dp[300][11];
    
    int solve(int i, int d, vector<int> &jobDifficulty)
    {
        if(d < 0)
            return 1e6;
        
        if(i == jobDifficulty.size())
            return d == 0 ? 0 : 1e6;
        
        if(dp[i][d] != -1)
            return dp[i][d];
        
        int ans = 1e6, mx = INT_MIN;
        for(int j = i; j < jobDifficulty.size(); j++)
        {
            mx = max(mx, jobDifficulty[j]);
            ans = min(ans, mx + solve(j + 1, d - 1, jobDifficulty));
        }
        return dp[i][d] = ans;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, d, jobDifficulty);
        if(ans == 1e6)
            ans = -1;
        return ans;
    }
};