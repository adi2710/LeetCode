int memo[100001];
class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int solve(int n, int late, int absent, vector<vector<vector<int>>> &dp) {
        if(n < 0)
            return 1;
        if(dp[n][late][absent] != -1)
            return dp[n][late][absent];
        int count = solve(n - 1, 0, absent, dp);
        if(absent == 0) {
            count = (1ll * count + solve(n - 1, 0, absent + 1, dp)) % MOD;
        }
        if(late <= 1) {
            count = (1ll * count + solve(n - 1, late + 1, absent, dp)) % MOD;
        }
        return dp[n][late][absent] = count;
    }

    int checkRecord(int n) {
        if(memo[0] == 0) {
            memset(memo, -1, sizeof(memo));
        }
        if(memo[n] != -1)
            return memo[n];
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (3, vector<int> (2, -1)));
        return memo[n] = solve(n - 1, 0, 0, dp);
    }
};
