class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int diff = nums[i] - k;
            int sum = k + nums[i];
            if(mp.find(diff) != mp.end())
                ans += mp[diff];
            if(mp.find(sum) != mp.end())
                ans += mp[sum];
            mp[nums[i]]++;
        }
        return ans;
    }
};