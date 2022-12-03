class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> dp(n);
        dp[0] = 1;
        for(int i = 0; i < primes.size(); i++)
            pq.push({primes[i], i, 0});
        for(int i = 1; i < n; i++)
        {
            int mn = pq.top()[0];
            dp[i] = mn;
            while(!pq.empty() && pq.top()[0] == mn)
            {
                vector<int> a = pq.top();
                pq.pop();
                if(1ll * dp[a[2] + 1] * primes[a[1]] <= INT_MAX)
                    pq.push({dp[a[2] + 1] * primes[a[1]], a[1], a[2] + 1});
            }
        }
        return dp[n - 1];
    }
};