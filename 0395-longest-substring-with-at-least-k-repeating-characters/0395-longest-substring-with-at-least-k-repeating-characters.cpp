class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> freq;
        unordered_set<char> st(s.begin(), s.end());
        int uniqueChars = st.size(), n = s.size(), ans = 0;
        for(int i = 1; i <= uniqueChars; i++)
        {
            int atLeastK = 0;
            for(int l = 0, r = 0; l < n; l++)
            {
                while(r < n && freq.size() <= i){
                    freq[s[r]]++;
                    if(freq[s[r]] == k)
                        atLeastK++;
                    r++;
                }
                if(atLeastK >= i)
                    ans = max(ans, freq.size() > i ? r - l - 1 : r - l);
                freq[s[l]]--;
                if(freq[s[l]] == k - 1)
                    atLeastK--;
                if(freq[s[l]] == 0)
                    freq.erase(s[l]);
            }
        }
        return ans;
    }
};