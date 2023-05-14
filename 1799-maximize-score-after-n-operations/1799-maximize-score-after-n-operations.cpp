class Solution {
public:
    
    int solve(int pairs, int mask, vector<int> &nums, vector<int> &dp)
    {
        if(2 * pairs == nums.size())
            return 0;
        if(dp[mask] != -1)
            return dp[mask];
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(((1 << i) & mask) > 0 || ((1 << j) & mask) > 0)
                    continue;
                int newMask = mask | (1 << i) | (1 << j);
                int sum = (pairs + 1) * __gcd(nums[i], nums[j]) + solve(pairs + 1, newMask, nums, dp);
                ans = max(ans, sum);
            }
        }
        return dp[mask] = ans;
    }
    
    int maxScore(vector<int>& nums) {
        vector<int> dp(1 << nums.size(), -1);
        return solve(0, 0, nums, dp);
    }
};