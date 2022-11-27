class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<long, int>> dp(nums.size());
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                long diff = 1l * nums[i] - nums[j];
                ans += dp[j][diff];
                dp[i][diff] += dp[j][diff];
                dp[i][diff]++;
            }
        }
        return ans;
    }
};