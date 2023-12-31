class Solution {
public:
    int maxLengthBetweenEqualCharacters(string &s) {
        int ans = -1;
        vector<int> pos(26, -1);
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(pos[ch - 'a'] != -1)
                ans = max(ans, i - pos[ch - 'a'] - 1);
            else
                pos[ch - 'a'] = i;
        }
        return ans;
    }
};