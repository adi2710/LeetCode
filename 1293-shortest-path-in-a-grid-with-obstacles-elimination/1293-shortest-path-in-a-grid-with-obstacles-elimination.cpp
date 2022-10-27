class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<tuple<int, int, int>> q;
        q.push({0, 0, k});
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        vector<vector<int>> vis(n, vector<int> (m, -1));
        vis[0][0] = k;
        while(!q.empty())
        {
            for(int i = q.size(); i >= 1; i--)
            {
                auto [r, c, obstacle] = q.front();
                q.pop();
                if(r == n - 1 && c == m - 1)
                    return ans;
                for(int idx = 0; idx < 4; idx++)
                {
                    int row = r + dx[idx], col = c + dy[idx], obst = obstacle;
                    if(row < 0 || row >= n || col < 0 || col >= m)
                        continue;
                    if(grid[row][col] == 1)
                    {
                        obst--;
                        if(obst < 0)
                            continue;
                    }
                    if(vis[row][col] >= obst)
                        continue;
                    
                    vis[row][col] = obst;
                    q.push({row, col, obst});
                }
            }
            ans++;
        }
        return -1;
    }
};