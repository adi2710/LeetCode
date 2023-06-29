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
        int key_mask = (1 << keys) - 1;
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>> (m, vector<bool> (1 << keys)));
        vis[0][0][0] = true;
        int ans = 0;
        vector<int> dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
        while(!q.empty())
        {
            for(int i = q.size(); i >= 1; i--)
            {
                vector<int> ar = q.front();
                q.pop();
                int r = ar[0], c = ar[1], cur_keys = ar[2];
                if(cur_keys == key_mask)
                    return ans;
                for(int j = 0; j < dr.size(); j++)
                {
                    int row = r + dr[j], col = c + dc[j];
                    if(row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == '#')
                        continue;
                    else if('a' <= grid[row][col] && grid[row][col] <= 'z')
                    {
                        int pos = grid[row][col] - 'a';
                        int new_key_mask = cur_keys | (1 << pos);
                        if(vis[row][col][new_key_mask])
                            continue;
                        q.push({row, col, new_key_mask});
                        vis[row][col][new_key_mask] = true;
                    }
                    else if('A' <= grid[row][col] && grid[row][col] <= 'Z')
                    {
                        int pos = grid[row][col] - 'A';
                        if(vis[row][col][cur_keys])
                            continue;
                        if((cur_keys & (1 << pos)))
                        {
                            q.push({row, col, cur_keys});
                            vis[row][col][cur_keys] = true;
                        }
                        else
                            continue;
                    }
                    else
                    {
                        if(vis[row][col][cur_keys])
                            continue;
                        q.push({row, col, cur_keys});
                        vis[row][col][cur_keys] = true;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};