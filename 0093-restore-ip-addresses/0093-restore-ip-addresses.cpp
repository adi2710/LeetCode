class Solution {
public:
    
    void solve(int i, int cnt, string &s, string str, vector<string> &ans)
    {
        if(i == s.size())
        {
            if(cnt == 0){
                ans.push_back(str);
                ans.back().pop_back();
            }
            return;
        }
        if(s[i] == '0')
        {
            str += s[i];
            str += ".";
            solve(i + 1, cnt - 1, s, str, ans);
            return;
        }
        string ss;
        for(int j = i; j < s.size() && j - i <= 2; j++)
        {
            ss += s[j];
            if(stoi(ss) <= 255)
                solve(j + 1, cnt - 1, s, str + ss + ".", ans);
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        solve(0, 4, s, "", ans);
        return ans;
    }
};