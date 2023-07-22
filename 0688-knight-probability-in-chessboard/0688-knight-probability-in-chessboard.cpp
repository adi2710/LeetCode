class Solution {
public:
    vector<int> dr = {-2,-2,2,2,-1,-1,1,1}, dc = {-1,1,-1,1,-2,2,-2,2};
    double solve(int r, int c, int k, int n, vector<vector<vector<double>>> &dp)
    {
        if(r < 0 || c < 0 || r >= n || c >= n)
            return 0;
        if(k == 0)
            return 1;
        if(dp[r][c][k] != -1)
            return dp[r][c][k];
        double ans = 0;
        for(int i = 0; i < dr.size(); i++)
        {
            int row = r + dr[i], col = c + dc[i];
            ans += solve(row, col, k - 1, n, dp);
        }
        return dp[r][c][k] = ans;
        
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>> (n, vector<double> (k + 1, -1)));
        double ans = solve(row, column, k, n, dp);
        ans /= pow(8, k);
        return ans;
    }
};