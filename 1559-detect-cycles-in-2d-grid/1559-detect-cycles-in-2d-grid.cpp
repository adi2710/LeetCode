class Solution {
public:
    
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    
    bool findCycle(int r, int c, int pre_r, int pre_c, vector<vector<bool>> &vis, vector<vector<char>> &grid)
    {
        if(vis[r][c])
            return true;
        vis[r][c] = true;
        bool cycle = false;
        for(int i = 0; i < 4; i++)
        {
            int row = r + dx[i], col = c + dy[i];
            if(0 <= row && row < grid.size() && 0 <= col && col < grid[0].size() && (row != pre_r || col != pre_c) && grid[row][col] == grid[r][c])
                cycle = cycle || findCycle(row, col, r, c, vis, grid);
        }
        return cycle;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m));
        bool ans = false;
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
            {
                if(!vis[r][c])
                    ans = ans || findCycle(r, c, r, c, vis, grid);
            }
        }
        return ans;
    }
};