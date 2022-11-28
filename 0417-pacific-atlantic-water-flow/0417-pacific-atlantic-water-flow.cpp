class Solution {
public:
    
    int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
    
    void dfs(int r, int c, vector<vector<bool>> &vis, vector<vector<int>> &matrix)
    {
        vis[r][c] = 1;
        for(int i = 0; i < 4; i++)
        {
            int x = dx[i], y = dy[i];
            if(r + x < 0 || c + y < 0 || r + x >= matrix.size() || c + y >= matrix[0].size() || vis[r + x][c + y] || matrix[r + x][c + y] < matrix[r][c])
                continue;
            dfs(r + x, c + y, vis, matrix);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m)), atlantic(n, vector<bool>(m));
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)
        {
            pacific[i][0] = 1;
            atlantic[i][m - 1] = 1;
        }
        for(int j = 0; j < m; j++)
        {
            pacific[0][j] = 1;
            atlantic[n - 1][j] = 1;
        }
        for(int i = 0; i < n; i++)
        {
            dfs(i, 0, pacific, heights);
            dfs(i, m - 1, atlantic, heights);
        }
        for(int j = 0; j < m; j++)
        {
            dfs(0, j, pacific, heights);
            dfs(n - 1, j, atlantic, heights);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};