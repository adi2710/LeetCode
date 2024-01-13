class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> mp(26);
        int ans = 0;
        for(char ch : s) {
            mp[ch - 'a']++;
        }
        for(char ch : t) {
            mp[ch - 'a']--;
        }
        for(int i = 0; i < 26; i++) {
            ans += abs(mp[i]);
        }
        return ans / 2;
    }
};