class Solution {
public:
    
    int dp[301][301];
    
    int solve(int l, int r, vector<int> &nums)
    {
        if(l > r)
            return 0;
        
        if(dp[l][r] != -1)
            return dp[l][r];
        
        int res = 0;
        for(int mid = l; mid <= r; mid++)
        {
            res = max(res, nums[l - 1] * nums[mid] * nums[r + 1] + solve(l, mid - 1, nums) + solve(mid + 1, r, nums));
        }
        return dp[l][r] = res;
    }
    
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return solve(1, nums.size() - 2, nums);
    }
};