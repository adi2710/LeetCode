class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i <= 31; i++)
        {
            int cnt = 0;
            for(int x : nums)
            {
                x = abs(x);
                if(x & (1 << i))
                    cnt++;
            }
            cnt %= 3;
            if(cnt)
                ans |= (1 << i);
        }
        int cnt = 0;
        for(int x : nums)
        {
            if(ans == x)
                cnt++;
        }
        return cnt == 1 ? ans : -ans;
    }
};