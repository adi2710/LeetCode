class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, nums[i] + nums[n - i - 1]);
        return ans;
    }
};