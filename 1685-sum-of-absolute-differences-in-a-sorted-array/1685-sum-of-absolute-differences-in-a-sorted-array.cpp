class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n  = nums.size(), suf = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans(n);
        for(int i = 0, pre = 0; i < n; i++)
        {
            suf -= nums[i];
            ans[i] = suf - nums[i] * (n - i - 1) + nums[i] * i - pre;
            pre += nums[i];
        }
        return ans;
    }
};