class Solution {
public:
    
    int solve(int r, int c1, int c2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        if(c1 < 0 || c1 >= grid[0].size() || c2 < 0 || c2 >= grid[0].size())
            return 0;
        if(r == grid.size())
            return 0;
        if(dp[r][c1][c2] != -1)
            return dp[r][c1][c2];
        int ans = INT_MIN;
        int s = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        for(int d1 = c1 - 1; d1 <= c1 + 1; d1++) {
            for(int d2 = c2 - 1; d2 <= c2 + 1; d2++) {
                ans = max(ans, s + solve(r + 1, d1, d2, grid, dp));
            }
        }
        return dp[r][c1][c2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>> (grid[0].size(), vector<int> (grid[0].size(), -1)));
        return solve(0, 0, grid[0].size() - 1, grid, dp);
    }
};