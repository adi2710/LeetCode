class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, n = s.size(), mxCnt = 0;
        unordered_map<char, int> freq;
        for(int l = 0, r = 0; l < n; l++)
        {
            while(r < n && r - l - mxCnt <= k)
            {
                mxCnt = max(mxCnt, ++freq[s[r]]);
                r++;
            }
            ans = max(ans, r - l - mxCnt > k ? r - l - 1: r - l);
            freq[s[l]]--;
        }
        return ans;
    }
};