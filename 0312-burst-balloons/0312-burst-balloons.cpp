class Solution {
public:
    int dp[302][302];
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        memset(dp, 0, sizeof(dp));
        for(int gap = 0; gap < n; gap++)
        {
            for(int l = 1, r = 1 + gap; l + 1 < n && r + 1 < n; l++, r++)
            {
                for(int mid = l; mid <= r; mid++)
                    dp[l][r] = max(dp[l][r], nums[l - 1] * nums[mid] * nums[r + 1] + dp[l][mid - 1] + dp[mid + 1][r]);
            }
        }
        return dp[1][n - 2];
    }
};