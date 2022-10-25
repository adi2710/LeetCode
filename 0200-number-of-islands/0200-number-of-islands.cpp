class Solution {
public:
    
    void floodfill(int r, int c, vector<vector<char>> &grid)
    {
        if(r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0')
            return;
        grid[r][c] = '0';
        floodfill(r - 1, c, grid);
        floodfill(r + 1, c, grid);
        floodfill(r, c - 1, grid);
        floodfill(r, c + 1, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1'){
                    floodfill(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};