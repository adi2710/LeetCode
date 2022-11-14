class Solution {
public:
    
    int dp[201][201];
    vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
    
    int findLIP(int r, int c, vector<vector<int>> &mat)
    {   
        if(dp[r][c] != -1)
            return dp[r][c];
        
        int ans = 1;
        for(int i = 0; i < 4; i++)
        {
            int row = dx[i] + r, col = dy[i] + c;
            if(row < 0 || col < 0 || row >= mat.size() || col >= mat[0].size() || mat[row][col] <= mat[r][c])
                continue;
            ans = max(ans, 1 + findLIP(row, col, mat));
        }
        return dp[r][c] = ans; 
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int r = 0; r < matrix.size(); r++)
        {
            for(int c = 0; c < matrix[0].size(); c++)
                ans = max(ans, findLIP(r, c, matrix));
        }
        return ans;
    }
};