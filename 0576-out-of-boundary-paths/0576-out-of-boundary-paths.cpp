class Solution {
public:
    
    const int mod = 1e9 + 7;
    int dp[51][51][51];
    
    int solve(int r, int c, int cnt, int mx, int m, int n)
    {
        if(cnt > mx)
            return 0;
        if(r < 0 || r >= m || c < 0 || c >= n)
            return 1;
        if(dp[r][c][cnt] != -1)
            return dp[r][c][cnt];
        long long up = solve(r - 1, c, cnt + 1, mx, m, n);
        long long down = solve(r + 1, c, cnt + 1, mx, m, n);
        long long left = solve(r, c - 1, cnt + 1, mx, m, n);
        long long right = solve(r, c + 1, cnt + 1, mx, m, n);
        return dp[r][c][cnt] = (up + down + left + right) % mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(startRow, startColumn, 0, maxMove, m, n);
    }
};