class Solution {
public:
    
    double power(double x, int n) {
        if(n == 0)
            return 1;
        
        if(n & 1) 
            return x * power(x, n - 1);
        double exp = power(x, n / 2);
        return exp * exp;
    }
    
    double myPow(double x, int n) {
        if(n == 0)
            return 1.0;
        double ans = 1.0;
        if(n < 0) {
            if(n == INT_MIN) {
                ans = 1.0 / x;
                n = INT_MAX;
            }
            else
                n = -n;
            x = 1.0 / x;
        }
        ans *= power(x, n);
        return ans;
    }
};