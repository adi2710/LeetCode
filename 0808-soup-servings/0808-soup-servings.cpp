unordered_map<int, unordered_map<int, double>> dp;
class Solution {
public:
    double solve(int a, int b)
    {
        if(a <= 0 && b <= 0)
            return 0.5;
        if(a <= 0)
            return 1;
        if(b <= 0)
            return 0;
        if(dp.find(a) != dp.end() && dp[a].find(b) != dp[a].end())
            return dp[a][b];
        return dp[a][b] = 0.25 * (solve(a - 4, b) + solve(a - 3, b - 1) + solve(a - 2, b - 2) + solve(a - 1, b - 3));
    }
    double soupServings(int n) {
        int m = ceil(n / 25.0);
        for(int i = 1; i <= m; i++)
        {
            if(solve(i, i) > 0.99999)
                return 1.0;
        }
        return solve(m, m);
    }
};