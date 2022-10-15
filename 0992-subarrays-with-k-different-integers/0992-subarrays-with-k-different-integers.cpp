class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size(), ans = 0;
        for(int i = 0, j = -1, r = 0; i < n; i++)
        {
            while(j + 1 < n && mp.size() < k)
                mp[nums[++j]]++;
            if(mp.size() == k)
            {
                if(r <= j)
                {
                    r = j;
                    while(r + 1 < n && mp.find(nums[r + 1]) != mp.end())
                        r++;
                }
                ans += r - j + 1;
            }
            mp[nums[i]]--;
            if(mp[nums[i]] == 0)
                mp.erase(nums[i]);
        }
        return ans;
    }
};