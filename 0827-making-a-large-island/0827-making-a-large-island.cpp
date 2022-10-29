class Solution {
public:
    
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    
    int dfs(int r, int c, int comp, vector<vector<int>> &grid)
    {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != 1)
            return 0;
        grid[r][c] = comp;
        int cnt = 1;
        for(int i = 0; i < 4; i++)
            cnt += dfs(r + dx[i], c + dy[i], comp, grid);
        return cnt;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), comp = 1, ans = 0;
        unordered_map<int, int> mp;
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
            {
                if(grid[r][c] == 1){
                    comp++;
                    mp[comp] = dfs(r, c, comp, grid);
                    ans = max(ans, mp[comp]);
                }
            }
        }
        if(comp == 1)
            return 1;
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
            {
                if(grid[r][c] == 0)
                {
                    unordered_set<int> st;
                    for(int i = 0; i < 4; i++)
                    {
                        int row = r + dx[i], col = c + dy[i];
                        if(row < 0 || row >= n || col < 0 || col >= m)
                            continue;
                        st.insert(grid[row][col]);
                    }
                    int sz = 1;
                    for(int com : st)
                        sz += mp[com];
                    ans = max(ans, sz);
                }
            }
        }
        return ans;
    }
};