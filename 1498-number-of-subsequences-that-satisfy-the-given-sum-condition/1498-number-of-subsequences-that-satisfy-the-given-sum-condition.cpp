class Solution {
public:
    int power(int a, int b,const int MOD)
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
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0, n = nums.size();
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        for(int i = 0, j = n - 1; i < n && 2 * nums[i] <= target; i++)
        {
            while(j >= i && nums[i] + nums[j] > target) j--;
            if(j < i)
                break;
            ans = (1ll * ans + power(2, j - i, MOD)) % MOD;
        }
        return ans;
    }
};