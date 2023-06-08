class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), r = 0, c = m - 1, ans = 0;
        while(r < n && c >= 0)
        {
            if(grid[r][c] < 0)
                c--;
            else
                ans += m - c - 1, r++;
        }
        if(r < n)
            ans += (m - c - 1) * (n - r);
        return ans;
    }
};