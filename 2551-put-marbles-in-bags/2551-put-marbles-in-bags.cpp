class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<long long> ar(n - 1);
        for(int i = 0; i + 1 < n; i++)
            ar[i] = 1ll * weights[i] + weights[i + 1];
        sort(ar.begin(), ar.end());
        long long min_sum = 0, max_sum = 0;
        for(int i = 0; i + 1 < k; i++)
            min_sum += ar[i];
        for(int i = n - k; i + 1 < n; i++)
            max_sum += ar[i];
        return max_sum - min_sum;
    }
};