class Solution {
    int solve(int i, int rem, vector<int> &nums, vector<vector<int>> &dp) {
        if(i == nums.size())
            return rem == 0 ? 0 : INT_MIN;

        if(dp[i][rem] != -1)
            return dp[i][rem];

        int take = nums[i] + solve(i + 1, (rem + nums[i]) % 3, nums, dp);
        int skip = solve(i + 1, rem, nums, dp);
        return dp[i][rem] = max(take, skip);
    }
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (3, -1));
        return solve(0, 0, nums, dp);
    }
};