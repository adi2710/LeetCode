class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long sufSum = accumulate(nums.begin(), nums.end(), 0l), preSum = 0;
        int ans = -1, mn = INT_MAX, n = nums.size();
        for(int i = 0; i < n - 1; i++)
        {
            preSum += nums[i];
            sufSum -= nums[i];
            if(mn > abs(preSum / (i + 1) - sufSum / (n - i - 1)))
            {
                mn = abs(preSum / (i + 1) - sufSum / (n - i - 1));
                ans = i;
            }
        }
        preSum += nums.back();
        if(mn > preSum / n)
        {
            mn = preSum / n;
            ans = n - 1;
        }
        return ans;
    }
};