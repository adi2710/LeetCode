class Solution {
public:
    
    void solve(int i, string &digits, string &st, vector<string> &mp, vector<string> &ans)
    {
        if(i == digits.size())
        {
            ans.push_back(st);
            return;
        }
        for(char ch : mp[digits[i] - '0'])
        {
            st += ch;
            solve(i + 1, digits, st, mp, ans);
            st.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string st;
        vector<string> ans;
        if(digits.empty())
            return ans;
        solve(0, digits, st, mp, ans);
        return ans;
    }
};