class Solution {
public:
    
    int find_next(int l, vector<vector<int>> &events, int num)
    {
        int pos = -1;
        int r = events.size();
        while(r - l > 1)
        {
            int mid = l + (r - l) / 2;
            if(events[mid][0] > num)
                r = mid;
            else
                l = mid;
        }
        return r;
    }
    
    int solve(int i, int k, vector<vector<int>> &events, vector<vector<int>> &dp)
    {
        if(i >= events.size() || k == 0)
            return 0;
        if(dp[i][k] != -1)
            return dp[i][k];
        int next = find_next(i, events, events[i][1]);
        return dp[i][k] = max(events[i][2] + solve(next, k - 1, events, dp), solve(i + 1, k, events, dp));
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int> (k + 1, -1));
        return solve(0, k, events, dp);
    }
};