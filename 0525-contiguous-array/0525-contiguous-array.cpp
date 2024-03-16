class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cnt = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            cnt += (nums[i] == 1 ? 1 : -1);
            if(mp.find(cnt) != mp.end())
                ans = max(ans, i - mp[cnt]);
            else
                mp[cnt] = i;
        }
        return ans;
    }
};