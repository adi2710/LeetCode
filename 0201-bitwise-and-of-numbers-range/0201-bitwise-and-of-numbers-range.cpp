class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for(int i = 0; i <= 30; i++)
        {
            long mask = 1ll << i;
            if(left & mask)
            {
                int rem = left - (left % mask);
                int set = rem / mask;
                if(set & 1 && right < rem + mask)
                    ans |= mask;
            }
        }
        return ans;
    }
};