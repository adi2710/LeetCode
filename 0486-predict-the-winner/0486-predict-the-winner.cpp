class Solution {
public:
    
    int solve(int l, int r, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(l > r)
            return 0;
        if(dp[l][r] != -1e8)
            return dp[l][r];
        int lf = nums[l] - solve(l + 1, r, nums, dp);
        int rt = nums[r] - solve(l, r - 1, nums, dp);
        return dp[l][r] = max(lf, rt);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size(), -1e8));
        return solve(0, nums.size() - 1, nums, dp) >= 0;
    }
};