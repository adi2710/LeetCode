class Solution {

    int solve(int i, int j, vector<int> &ar1, vector<int> &ar2, vector<vector<int>>& dp)
    {
        if (i == ar1.size())
            return 0;
        if (dp[i][j + 1] != -1)
            return dp[i][j + 1];
        if (i == 0) {
            int p1 = solve(i + 1, j, ar1, ar2, dp);
            int p2 = solve(i + 1, 0, ar1, ar2, dp);
            if (p2 < INT_MAX)
                p2++;
            return dp[i][j + 1] = min(p1, p2);
        }
        int prev = j == -1 ? ar1[i - 1] : ar2[j];
        int p1 = prev < ar1[i] ? solve(i + 1, -1, ar1, ar2, dp) : INT_MAX, p2 = INT_MAX;
        int pos = upper_bound(ar2.begin(), ar2.end(), prev) - ar2.begin();
        if (pos < ar2.size())
        {
            p2 = solve(i + 1, pos, ar1, ar2, dp);
            if (p2 < INT_MAX)
                p2++;
        }
        return dp[i][j + 1] = min(p1, p2);
    }

public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        vector<vector<int>> dp(arr1.size(), vector<int> (arr2.size() + 1, -1));
        int ans = solve(0, -1, arr1, arr2, dp);
        if (ans == INT_MAX)
            ans = -1;
        return ans;
    }
};