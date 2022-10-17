class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i <= 31; i++)
        {
            int cnt = 0;
            for(int x : nums)
            {
                if(x & (1 << i))
                    cnt++;
            }
            cnt %= 3;
            if(cnt % 3 != 0)
                ans |= (1 << i);
        }
        
        return ans;
    }
};