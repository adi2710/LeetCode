class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> mp(201);
        const int BASE = 100;
        for(int x : nums) {
            mp[x + BASE]++;
        }
        sort(nums.begin(), nums.end(), [&](const int &a, const int &b) {
            if(mp[a + BASE] == mp[b + BASE])
                return a > b;
            return mp[a + BASE] < mp[b + BASE];
        });
        return nums;
    }
};