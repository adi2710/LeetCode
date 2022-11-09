class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long> dp(n), pointers(primes.size());
        dp[0] = 1;
        for(int i = 1; i < n; i++)
        {
            long mn = INT_MAX;
            for(int j = 0; j < primes.size(); j++)
                mn = min(mn, dp[pointers[j]] * primes[j]);
            dp[i] = mn;
            for(int j = 0; j < primes.size(); j++)
            {
                if(mn == dp[pointers[j]] * primes[j])
                    pointers[j]++;
            }
        }
        return dp[n - 1];
    }
};