class Solution {
public:
    
    int solve(int l, int r, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if(l > r)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        int ans = INT_MAX;
        for(int mid = l; mid <= r; mid++)
            ans = min(ans, cuts[r + 1] - cuts[l - 1] + solve(l, mid - 1, cuts, dp) + solve(mid + 1, r, cuts, dp));
        return dp[l][r] = ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(cuts.size(), vector<int> (cuts.size(), -1));
        return solve(1, cuts.size() - 2, cuts, dp);
    }
};