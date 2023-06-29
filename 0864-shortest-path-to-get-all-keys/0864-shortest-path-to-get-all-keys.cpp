class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int keys = 0, n = grid.size(), m = grid[0].size();
        queue<vector<int>> q;
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
            {
                if(grid[r][c] == '@')
                    q.push({r, c, 0});
                else if('a' <= grid[r][c] && grid[r][c] <= 'z')
                    keys++;
            }
        }
        int total_key_mask = (1 << keys) - 1;
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>> (m, vector<bool> (total_key_mask + 1)));
        vis[0][0][0] = true;
        int ans = 0;
        vector<int> dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
        while(!q.empty())
        {
            for(int i = q.size(); i >= 1; i--)
            {
                vector<int> ar = q.front();
                q.pop();
                int r = ar[0], c = ar[1], cur_key_mask = ar[2];
                if(cur_key_mask == total_key_mask)
                    return ans;
                for(int j = 0; j < dr.size(); j++)
                {
                    int row = r + dr[j], col = c + dc[j], new_key_mask = cur_key_mask;
                    if(row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == '#')
                        continue;
                    else if('a' <= grid[row][col] && grid[row][col] <= 'z')
                        new_key_mask |= (1 << (grid[row][col] - 'a'));
                    else if('A' <= grid[row][col] && grid[row][col] <= 'Z')
                    {
                        if((new_key_mask & (1 << (grid[row][col] - 'A'))) == 0)
                            continue;
                    }
                    if(!vis[row][col][new_key_mask])
                    {
                        vis[row][col][new_key_mask] = true;
                        q.push({row, col, new_key_mask});
                    } 
                }
            }
            ans++;
        }
        return -1;
    }
};