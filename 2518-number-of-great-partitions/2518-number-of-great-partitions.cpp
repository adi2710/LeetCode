class Solution {
public:
    
    int dp[1001][1001];
    const int MOD = 1e9 + 7;
    int solve(int i, int k, vector<int> &nums)
    {
        if(k <= 0)
            return 0;
        if(i == nums.size())
            return 1;
        if(dp[i][k] != -1)
            return dp[i][k];
        return dp[i][k] = (solve(i + 1, k - nums[i], nums) + solve(i + 1, k, nums)) % MOD;
    }
    
    int power(int a, int b)
    {
        int res = 1;
        while(b)
        {
            if(b & 1)
                res = (1ll * res * a) % MOD;
            a = (1ll * a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
    
    int countPartitions(vector<int>& nums, int k) {
        if(accumulate(nums.begin(), nums.end(), 0ll) < 2 * k)
            return 0;
        memset(dp, -1, sizeof(dp));
        int count = solve(0, k, nums);
        int ans = (power(2, nums.size()) - 2ll * count) % MOD;
        return (MOD + ans) % MOD;
    }
};