class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
            {
                if(grid[r][c] == 2)
                    q.push({r, c});
            }
        }
        vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        while(!q.empty())
        {
            ans++;
            for(int i = q.size(); i >= 1; i--)
            {
                auto [r, c] = q.front();
                q.pop();
                for(int j = 0; j < 4; j++)
                {
                    int row = r + dx[j], col = c + dy[j];
                    if(0 <= row && row < n && 0 <= col && col < m && grid[row][col] == 1)
                    {
                        q.push({row, col});
                        grid[row][col] = 2;
                    }
                }
            }
        }
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
            {
                if(grid[r][c] == 1)
                    return -1;
            }
        }
        return max(0, ans - 1);
    }
};