int dp[100001][3][2];
class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int solve(int n, int late, int absent) {
        if(n == 0)
            return 1;
        if(dp[n][late][absent] != -1)
            return dp[n][late][absent];
        int count = solve(n - 1, 0, absent);
        if(absent == 0) {
            count = (1ll * count + solve(n - 1, 0, absent + 1)) % MOD;
        }
        if(late <= 1) {
            count = (1ll * count + solve(n - 1, late + 1, absent)) % MOD;
        }
        return dp[n][late][absent] = count;
    }

    int checkRecord(int n) {
        if(dp[0][0][0] == 0) {
            memset(dp, -1, sizeof(dp));
        }
        return solve(n, 0, 0);
    }
};
