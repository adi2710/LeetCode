class Solution {
public:
    
    void buildPrefix(int cnt, vector<int> &nums, vector<int> &pre)
    {
        int l = 0, sum = 0, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            pre[i] = max(i > 0 ? pre[i - 1] : 0, sum);
            if(i >= cnt - 1)
                sum -= nums[l++];
        }
    }
    
    void buildSuffix(int cnt, vector<int> &nums, vector<int> &suf)
    {
        int n = nums.size(), r = n - 1, sum = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            sum += nums[i];
            suf[i] = max(i + 1 < n ? suf[i + 1] : 0, sum);
            if(n - i >= cnt)
                sum -= nums[r--];
        }
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size(), ans = 0;
        vector<int> pre(n), suf(n);
        buildPrefix(firstLen, nums, pre);
        buildSuffix(secondLen, nums, suf);
        for(int i = firstLen - 1; i < n - secondLen; i++)
            ans = max(ans, pre[i] + suf[i + 1]);
        buildPrefix(secondLen, nums, pre);
        buildSuffix(firstLen, nums, suf);
        for(int i = secondLen - 1; i < n - firstLen; i++)
            ans = max(ans, pre[i] + suf[i + 1]);
        return ans;
    }
};