class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int l = 0, r = -1, rr = -1, n = nums.size(); l < n; l++)
        {
            while(r + 1 < n && mp.size() < k)
                mp[nums[++r]]++;
            if(mp.size() == k)
            {
                if(rr <= r)
                {
                    rr = r + 1;
                    while(rr < n && mp.find(nums[rr]) != mp.end())
                        rr++;
                }
                ans += rr - r;
            }
            mp[nums[l]]--;
            if(mp[nums[l]] == 0)
                mp.erase(nums[l]);
        }
        return ans;
    }
};