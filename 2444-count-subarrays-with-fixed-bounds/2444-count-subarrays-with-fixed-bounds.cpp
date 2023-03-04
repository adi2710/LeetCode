class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        map<int, int> mp;
        int n = nums.size();
        long long ans = 0;
        for(int l = 0, r = -1, rr = 0; l < n; l++)
        {
            r = max(r, l - 1);
            while(r + 1 < n && (mp.empty() || ((*mp.begin()).first > minK || (*--mp.end()).first < maxK)))
                mp[nums[++r]]++;
            if((*mp.begin()).first == minK && (*--mp.end()).first == maxK)
            {
                rr = max(r, rr);
                while(rr + 1 < n && nums[rr + 1] <= maxK && nums[rr + 1] >= minK)
                    rr++;
                ans += rr - r + 1;
            }
            mp[nums[l]]--;
            if(mp[nums[l]] == 0)
                mp.erase(nums[l]);
        }
        return ans;
    }
};