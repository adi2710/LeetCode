class Solution {
public:
    
    string solve(int &i, string &s)
    {
        string res;
        while(i < s.size() && s[i] != ']')
        {
            if(!isdigit(s[i]))
                res += s[i++];
            else
            {
                int n = 0;
                while(i < s.size() && s[i] != '[')
                    n = n * 10 + s[i++] - '0';
                i++;
                string next = solve(i, s);
                i++;
                while(n--)
                    res += next;
            }
        }
        return res;
    }
    
    string decodeString(string s) {
        int i = 0;
        return solve(i, s);
    }
};