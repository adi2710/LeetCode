class Solution {
public:
    int balancedString(string s) {
        int n = s.size(), ans = n;
        unordered_map<char, int> freq;
        for(char ch : s)
            freq[ch]++;
        for(int l = 0, r = 0; l < n; l++)
        {
            r = max(r, l);
            while(r < n && (max({freq['Q'], freq['W'], freq['E'], freq['R']}) > n / 4))
                freq[s[r++]]--;
            if(max({freq['Q'], freq['W'], freq['E'], freq['R']}) <= n / 4)
                ans = min(ans, r - l);
            freq[s[l]]++;
        }
        return ans;
    }
};