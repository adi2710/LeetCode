class Solution {
public:
    
    bool isReachable(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool> (m));
        for(int c = 0; c < m; c++)
        {
            if(grid[0][c] == 0)
            {
                q.push({0, c});
                vis[0][c] = true;
            }
        }
        vector<int> dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
        while(!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            if(r == n - 1)
                return true;
            for(int i = 0; i < dr.size(); i++)
            {
                int row = r + dr[i], col = c + dc[i];
                if(row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 1 || vis[row][col])
                    continue;
                q.push({row, col});
                vis[row][col] = true;
            }
        }
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = -1, r = cells.size();
        vector<vector<int>> grid(row, vector<int> (col));
        while(r - l > 1)
        {
            int mid = l + (r - l) / 2;
            for(int i = l + 1; i <= mid; i++)
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
            if(isReachable(grid))
                l = mid;
            else
            {
                for(int i = l + 1; i <= mid; i++)
                    grid[cells[i][0] - 1][cells[i][1] - 1] = 0;
                r = mid;
            }
        }
        return l + 1;
    }
};