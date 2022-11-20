class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sum = 0, sign = 1, n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(isdigit(s[i]))
            {
                int num = 0;
                while(i < n && isdigit(s[i]))
                    num = num * 10 + (s[i++] - '0');
                i--;
                sum += num * sign;
                sign = 1;
            }
            else if(s[i] == '-')
                sign *= -1;
            else if(s[i] == '(')
            {
                st.push(sum);
                st.push(sign);
                sum = 0, sign = 1;
            }
            else if(s[i] == ')')
            {
                sum *= st.top();
                st.pop();
                sum += st.top();
                st.pop();
                sign = 1;
            }
        }
        return sum;
    }
};