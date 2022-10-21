class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, n = s.size();
        for(char ch = 'A'; ch <= 'Z'; ch++)
        {
            int diff = 0;
            for(int l = 0, r = 0; l < n; l++)
            {
                while(r < n && diff <= k)
                {
                    if(s[r] != ch)
                        diff++;
                    r++;
                }
                ans = max(ans, diff > k ? r - l - 1: r - l);
                if(s[l] != ch)
                    diff--;
            }
        }
        return ans;
    }
};