class Solution {
public:
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(m);
        for(int c = 0; c < m; c++)
        {
            int cur = c;
            for(int r = 0; r < n; r++)
            {
                int next = cur + grid[r][cur];
                if(next < 0 || next >= m || grid[r][cur] != grid[r][next])
                {
                    cur = -1;
                    break;
                }
                cur = next;
            }
            ans[c] = cur;
        }
        return ans;
    }
};