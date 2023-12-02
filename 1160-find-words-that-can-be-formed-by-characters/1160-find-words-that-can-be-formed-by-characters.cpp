class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> mp(26);
        int ans = 0;
        for(char ch : chars)
            mp[ch - 'a']++;
        for(string &word : words) {
            vector<int> mp1(26);
            for(char ch : word) {
                mp1[ch - 'a']++;
            }
            bool fl = 1;
            for(int i = 0; i < 26; i++) {
                if(mp[i] < mp1[i]) {
                    fl = 0;
                    break;
                }
            }
            if(fl)
                ans += word.size();
        }
        return ans;
    }
};