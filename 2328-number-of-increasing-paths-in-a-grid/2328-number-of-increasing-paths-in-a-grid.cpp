class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    const int MOD = 1e9 + 7;
    int solve(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if(dp[r][c] != -1)
            return dp[r][c];
        int path = 1;
        for(int i = 0; i < dx.size(); i++)
        {
            int row = r + dx[i], col = c + dy[i];
            if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] <= grid[r][c])
                continue;
            path = (1ll * path + solve(row, col, grid, dp)) % MOD;
        }
        return dp[r][c] = path;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), -1));
        for(int r = 0; r < grid.size(); r++)
        {
            for(int c = 0; c < grid[0].size(); c++)
                ans = (1ll * ans + solve(r, c, grid, dp)) % MOD;
        }
        return ans;
    }
};