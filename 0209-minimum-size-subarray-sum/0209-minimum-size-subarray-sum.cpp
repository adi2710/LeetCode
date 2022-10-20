class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), sum = 0, ans = INT_MAX, l = 0, r = 0;
        while(r < n)
        {
            while(r < n && sum < target)
                sum += nums[r++];
            if(sum >= target)
                ans = min(ans, r - l);
            while(l < r && sum >= target)
                sum -= nums[l++];
            if(ans != INT_MAX)
                ans = min(ans, r - l + 1);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};