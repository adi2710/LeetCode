class Solution {
public:
    
    int solve(int l, int r, int pos, int k, vector<long long> &pre)
    {
        long long num = pre[pos] - pre[pos - 1];
        while(r - l > 1)
        {
            int mid = l + (r - l) / 2;
            long long sum = pre[mid] - pre[pos];
            if((mid - pos) * num - sum <= k)
                l = mid;
            else
                r = mid;
        }
        return l - pos + 1;
    }
    
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        vector<long long> pre(n + 1);
        for(int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + nums[i - 1];
        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans = max(ans, solve(i, n + 1, i, k, pre));
        return ans;
    }
};