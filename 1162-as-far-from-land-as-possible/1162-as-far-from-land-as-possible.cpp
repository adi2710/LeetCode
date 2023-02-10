class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1){
                    q.push({i - 1, j});
                    q.push({i + 1, j});
                    q.push({i, j - 1});
                    q.push({i, j + 1});
                }
            }
        }
        while(!q.empty())
        {
            ans++;
            for(int i = q.size(); i >= 1; i--)
            {
                auto [r, c] = q.front();
                q.pop();
                if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0)
                {
                    grid[r][c] = ans;
                    q.push({r - 1, c});
                    q.push({r + 1, c});
                    q.push({r, c - 1});
                    q.push({r, c + 1});
                }
            }
        }
        return ans == 1 ? -1 : ans - 1;
    }
};