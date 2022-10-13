class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), cnt = 0, ans = 0;
        while(r < n)
        {
            while(r < n && cnt <= k)
            {
                cnt += nums[r] == 0;
                r++;
            }
            
            ans = max(ans, cnt <= k ? r - l : r - l - 1);
            while(l <= r && cnt > k)
            {
                cnt -= nums[l] == 0;
                l++;
            }
        }
        return ans;
    }
};