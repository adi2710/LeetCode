class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>> mp(26);
        for(int i = 0; i < s.size(); i++)
            mp[s[i] - 'a'].emplace_back(i);
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if(mp[i].size() <= 1)
                continue;
            int st = mp[i].front(), en = mp[i].back();
            for(int j = 0; j < 26; j++) {
                int l = 0, r = (int)mp[j].size() - 1;
                while(l <= r) {
                    int mid = l + (r - l) / 2;
                    if(st < mp[j][mid] && mp[j][mid] < en) {
                        ans++;
                        break;
                    }
                    else if(mp[j][mid] < st)
                        l = mid + 1;
                    else
                        r = mid - 1;
                }
            }
        }
        return ans;
    }
};
