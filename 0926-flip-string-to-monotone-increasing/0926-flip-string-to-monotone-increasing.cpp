class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size(), ans = n, count_one = 0, count_zero = 0;
        for(char ch : s)
        {
            if(ch == '0')
                count_zero++;
        }
        for(int i = 0; i <= n; i++)
        {
            ans = min(ans, count_zero + count_one);
            if(i < n && s[i] == '0')
                count_zero--;
            if(i < n && s[i] == '1')
                count_one++;
        }
        return ans;
    }
};