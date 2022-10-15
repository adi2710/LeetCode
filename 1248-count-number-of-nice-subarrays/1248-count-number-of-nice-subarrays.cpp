class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for(int i = 0, j = -1, r = 0, cnt = 0; i < n; i++)
        {
            while(j + 1 < n && cnt < k)
                cnt += nums[++j] & 1;
            if(cnt == k)
            {
                if(r <= j){
                    r = j;
                    while(r + 1 < n && nums[r + 1] & 1 ^ 1)
                        r++;
                }
                ans += r - j + 1;
            }
            cnt -= nums[i] & 1;
        }
        return ans;
    }
};