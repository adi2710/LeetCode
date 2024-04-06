class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt = 0;
        string ans1, ans2;
        for(char ch : s)
        {
            if(ch == '(')
                cnt++;
            else if(ch == ')')
                cnt--;
            if(cnt >= 0)
                ans1 += ch;
            else
                cnt = 0;
        }
        cnt = 0;
        for(int i = ans1.size() - 1; i >= 0; i--)
        {
            if(ans1[i] == ')')
                cnt++;
            else if(ans1[i] == '(')
                cnt--;
            if(cnt >= 0)
                ans2 += ans1[i];
            else
                cnt = 0;
        }
        reverse(ans2.begin(), ans2.end());
        return ans2;
    }
};