class Solution {
public:
    
    int dp[100001];
    
    bool solve(int i, vector<int> &nums)
    {
        int n = nums.size();
        if(i == n)
            return true;
        
        if(dp[i] != -1)
            return dp[i];
        
        bool fl = 0;
        if(i + 1 < n && nums[i] == nums[i + 1])
            fl = solve(i + 2, nums);
        if(i + 2 < n && nums[i] == nums[i + 1] && nums[i] == nums[i + 2])
            fl |= solve(i + 3, nums);
        if(i + 2 < n && nums[i] == nums[i + 1] - 1 && nums[i] == nums[i + 2] - 2)
            fl |= solve(i + 3, nums);
        
        return dp[i] = fl;
    }
    
    bool validPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums);
    }
};