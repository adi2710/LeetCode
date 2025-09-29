class Solution {
    int solve(int i, int j, vector<int> &values, vector<vector<int>> &dp) {
        if(i + 2 > j) {
            return 0;
        }

        if(i + 2 == j) {
            return values[i] * values[i + 1] * values[j];
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int minVal = INT_MAX;
        for(int k = i + 1; k < j; k++) {
            minVal = min(minVal, values[i] * values[k] * values[j] + solve(i, k, values, dp) + solve(k, j, values, dp));
        }
        return dp[i][j] = minVal;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, n - 1, values, dp);
    }
};