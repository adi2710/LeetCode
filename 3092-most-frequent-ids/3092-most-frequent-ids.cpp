class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, long long> mp1;
        map<long long, unordered_set<int>> mp2;
        int n = nums.size();
        vector<long long> ans(n);
        for(int i = 0; i < n; i++) {
            if(mp1[nums[i]] > 0) {
                mp2[mp1[nums[i]]].erase(nums[i]);
                if(mp2[mp1[nums[i]]].empty())
                    mp2.erase(mp1[nums[i]]);
            }
            mp1[nums[i]] += freq[i];
            long long cnt = mp1[nums[i]];
            mp2[cnt].insert(nums[i]);
            ans[i] = (*(--mp2.end())).first;
        }
        return ans;
    }
};