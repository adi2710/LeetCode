class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), sum = 0, ans = 0;
        for(int l = 0, r = -1, rr = 0; l < n; l++)
        {
            while(r + 1 < n && sum < goal)
                sum += nums[++r];
            if(r < l)
            {
                sum += nums[l];
                r = l;
            }
            if(sum == goal)
            {
                if(rr <= r)
                {
                    rr = r + 1;
                    while(rr < n && nums[rr] == 0)
                        rr++;
                }
                ans += rr - r;
            }
            sum -= nums[l];
        }
        return ans;
    }
};