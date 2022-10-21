class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> st(s.begin(), s.end());
        int ans = 0, n = s.size();
        for(char ch : st)
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