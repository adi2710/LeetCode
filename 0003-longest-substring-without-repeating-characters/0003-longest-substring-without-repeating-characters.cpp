class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0;
        unordered_map<char, int> mp;
        for(int i = 0, j = 0; i < n; i++)
        {
            if(mp.find(s[i]) != mp.end())
                j = max(j, mp[s[i]] + 1);
            mp[s[i]] = i;
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};