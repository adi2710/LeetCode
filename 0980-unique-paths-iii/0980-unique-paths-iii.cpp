class Solution {
public:
    
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    
    int solve(int r, int c, int count, vector<vector<int>> &grid)
    {
        if(grid[r][c] == 2 && count == 1)
            return 1;
        
        int cnt = 0, temp = grid[r][c];
        grid[r][c] = -1;
        for(int i = 0; i < dx.size(); i++)
        {
            int row = r + dx[i], col = c + dy[i];
            if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == -1)
                continue;
            cnt += solve(row, col, count - 1, grid);
        }
        grid[r][c] = temp;
        return cnt;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sr = -1, sc = -1, count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                    sr = i, sc = j;
                if(grid[i][j] != -1)
                    count++;
            }
        }
        return solve(sr, sc, count, grid);
    }
};