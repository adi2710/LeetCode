class Solution {
public:
    
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    
    void dfs(int r, int c, vector<vector<int>> &grid, queue<pair<int, int>> &q, vector<vector<bool>> &vis)
    {
        q.push({r, c});
        grid[r][c] = 0;
        vis[r][c] = true;
        for(int idx = 0; idx < 4; idx++)
        {
            int row = r + dx[idx], col = c + dy[idx];
            if(0 <= row && row < grid.size() && 0 <= col && col < grid[0].size() && grid[row][col] == 1)
                dfs(row, col, grid, q, vis);
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
        {
            bool fl = false;
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1){
                    dfs(i, j, grid, q, vis);
                    fl = true;
                    break;
                }
            }
            if(fl)
                break;
        }
        int ans = 0;
        while(!q.empty())
        {
            for(int i = q.size(); i >= 1; i--)
            {
                auto [r, c] = q.front();
                q.pop();
                if(grid[r][c] == 1)
                    return ans - 1;
                for(int idx = 0; idx < 4; idx++)
                {
                    int row = r + dx[idx], col = c + dy[idx];
                    if(0 <= row && row < n && 0 <= col && col < m && !vis[row][col])
                    {
                        q.push({row, col});
                        vis[row][col] = true;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};