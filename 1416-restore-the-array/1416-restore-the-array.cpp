class Solution {
public:
    
    const int MOD = 1e9 + 7;
    
    int solve(int i, string &s, int &k, vector<int> &dp)
    {
        if(i == s.size())
            return 1;
        if(s[i] == '0')
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int count = 0;
        for(int j = i; j < s.size(); j++)
        {
            string num = s.substr(i, j - i + 1);
            if(stoll(num) <= k)
                count = (1ll * count + solve(j + 1, s, k, dp)) % MOD;
            else
                break;
        }
        return dp[i] = count;
    }
    
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(), -1);
        return solve(0, s, k, dp);
    }
};