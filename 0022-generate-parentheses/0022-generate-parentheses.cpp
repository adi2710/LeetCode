class Solution {
public:
    
    void solve(int open, int close, int n, string &st, vector<string> &ans) {
        if(open == n && close == n) {
            ans.push_back(st);
            return;
        }
        
        if(open < n) {
            st.push_back('(');
            solve(open + 1, close, n, st, ans);
            st.pop_back();
        } 
        if(open > close) {
            st.push_back(')');
            solve(open, close + 1, n, st, ans);
            st.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string st;
        solve(0, 0, n, st, ans);
        return ans;
    }
};