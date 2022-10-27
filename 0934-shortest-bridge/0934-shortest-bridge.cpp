class Solution {
public:
    
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    
    void dfs(int r, int c, vector<vector<int>> &grid, set<pair<int, int>> &vis)
    {
        vis.insert({r, c});
        grid[r][c] = 0;
        for(int idx = 0; idx < 4; idx++)
        {
            int row = r + dx[idx], col = c + dy[idx];
            if(0 <= row && row < grid.size() && 0 <= col && col < grid[0].size() && grid[row][col] == 1 && vis.find({row, col}) == vis.end())
                dfs(row, col, grid, vis);
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        set<pair<int, int>> island1, island2;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && island1.empty())
                    dfs(i, j, grid, island1);
                else if(grid[i][j] == 1 && !island1.empty())
                    dfs(i, j, grid, island2);
            }
        }
        queue<pair<int, int>> q;
        for(auto coor : island1)
            q.push(coor);
        int ans = 0;
        while(!q.empty())
        {
            for(int i = q.size(); i >= 1; i--)
            {
                auto [r, c] = q.front();
                q.pop();
                if(island2.find({r, c}) != island2.end())
                    return ans - 1;
                for(int idx = 0; idx < 4; idx++)
                {
                    int row = r + dx[idx], col = c + dy[idx];
                    if(0 <= row && row < n && 0 <= col && col < m && island1.find({row, col}) == island1.end())
                    {
                        q.push({row, col});
                        island1.insert({row, col});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};