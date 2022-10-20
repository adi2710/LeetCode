class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0, ans = 0;
        for(int l = 0, r = -1, rr = 0; l < n; l++)
        {
            while(r + 1 < n && cnt < k)
            {
                r++;
                cnt += nums[r] & 1;
            }
            if(cnt == k)
            {
                if(rr <= r)
                {
                    rr = r + 1;
                    while(rr < n && (nums[rr] & 1 ^ 1))
                        rr++;
                }
                ans += rr - r;
            }
            cnt -= nums[l] & 1;
        }
        return ans;
    }
};