class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size(), ans = 0;
        sort(arr.begin(), arr.end());
        
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[arr[i]] = i;
        
        vector<int> dp(n, 1);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(arr[i] % arr[j] == 0)
                {
                    int right = arr[i] / arr[j];
                    if(mp.find(right) != mp.end())
                        dp[i] = (dp[i] + (1ll * dp[j] * dp[mp[right]]) % MOD) % MOD;
                }
            }
            ans = (ans + dp[i]) % MOD;
        }
        
        return ans;
    }
};