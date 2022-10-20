class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), l = 0, r = 0, cnt = 0, ans = 0;
        vector<int> freq(3);
        for(l = 0; l < n; l++)
        {
            while(r < n && cnt < 3)
            {
                if(freq[s[r] - 'a'] == 0)
                    cnt++;
                freq[s[r] - 'a']++;
                r++;
            }
            if(cnt == 3)
                ans += n - r + 1;
            if(freq[s[l] - 'a'] == 1)
                cnt--;
            freq[s[l] - 'a']--;
        }
        return ans;
    }
};