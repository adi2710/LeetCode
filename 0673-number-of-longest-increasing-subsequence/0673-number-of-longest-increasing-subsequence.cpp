class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1), lis_cnt(n, 1);
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                {
                    if(lis[i] < 1 + lis[j])
                    {
                        lis_cnt[i] = lis_cnt[j];
                        lis[i] = 1 + lis[j];
                    }
                    else if(lis[i] == 1 + lis[j])
                        lis_cnt[i] += lis_cnt[j];;
                }
            }
        }
        int mx = 0, ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(mx < lis[i])
            {
                mx = lis[i];
                ans = lis_cnt[i];
            }
            else if(mx == lis[i])
                ans += lis_cnt[i];
        }
        return ans;
    }
};