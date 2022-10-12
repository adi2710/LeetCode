class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int sign = dividend < 0 == divisor < 0 ? 1 : -1;
        long divi = labs(dividend), divs = labs(divisor), ans = 0;
        for(int i = 31; i >= 0; i--)
        {
            if(divi - (divs << i) >= 0)
            {
                divi -= (divs << i);
                ans += (1 << i);
            }
        }
        return ans * sign;
    }
};