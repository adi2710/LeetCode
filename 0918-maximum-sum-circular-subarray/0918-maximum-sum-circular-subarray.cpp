class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), suf_sum = 0, sum = 0, pre_sum = 0, ans1 = INT_MIN, ans2 = INT_MIN;
        vector<int> suf_max(n);
        suf_max.back() = suf_sum = nums.back();
        for(int i = n - 2; i >= 0; i--)
        {
            suf_sum += nums[i];
            suf_max[i] = max(suf_max[i + 1], suf_sum);
        }
        for(int i = 0; i < n; i++)
        {
            sum = max(sum, 0) + nums[i];
            ans1 = max(ans1, sum);
            ans2 = max(ans2, pre_sum + suf_max[i]);
            pre_sum += nums[i];
        }
        return max(ans1, ans2);
    }
};