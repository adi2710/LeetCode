class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i <= 30; i++)
        {
            int mask = 1 << i, cnt = 0;
            for(int x : nums)
            {
                if(x & mask)
                    cnt++;
            }
            ans += cnt * (nums.size() - cnt);
        }
        return ans;
    }
};