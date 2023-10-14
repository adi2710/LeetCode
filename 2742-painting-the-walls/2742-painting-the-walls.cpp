class Solution {
public:
    
    int solve(int i, int cnt, vector<int> &cost, vector<int> &time, vector<vector<int>> &dp)
    {
        if(cnt >= cost.size())
            return 0;
        if(i == cost.size())
            return INT_MAX;
        if(dp[i][cnt] != -1)
            return dp[i][cnt];
        int take = solve(i + 1, cnt + 1 + time[i], cost, time, dp);
        take = take == INT_MAX ? INT_MAX : take + cost[i];
        int skip = solve(i + 1, cnt, cost, time, dp);
        return dp[i][cnt] = min(take, skip);
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(cost.size(), vector<int> (cost.size(), -1));
        return solve(0, 0, cost, time, dp);
    }
};