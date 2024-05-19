class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<int> diff(nums.size());
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans += nums[i];
            diff[i] = (nums[i] ^ k) - nums[i];
        }
        sort(diff.rbegin(), diff.rend());
        for(int i = 0; i + 1 < nums.size(); i += 2) {
            if(diff[i] + diff[i + 1] > 0)
                ans += diff[i] + diff[i + 1];
            else
                break;
        }
        return ans;
    }
};