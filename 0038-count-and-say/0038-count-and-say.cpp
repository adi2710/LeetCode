class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i <= n; i++)
        {
            string temp;
            char st = ans[0];
            int cnt = 0;
            for(char ch : ans)
            {
                if(ch == st)
                    cnt++;
                else
                {
                    temp += to_string(cnt) + st;
                    cnt = 1;
                    st = ch;
                }
            }
            temp += to_string(cnt) + st;
            ans = temp;
        }
        return ans;
    }
};