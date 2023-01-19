class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mp(k);
        int sum = 0, ans = 0;
        mp[0] = 1;
        for(int num : nums)
        {
            sum = (sum + num) % k;
            sum = (sum + k) % k;
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};