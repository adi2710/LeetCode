class Solution {
public:
    
    void solve(int i, string &no, unordered_set<string> &st, string &ans) {
        if(i == st.size()) {
            if(st.find(no) == st.end())
                ans = no;
            return;
        }
        
        if(!ans.empty())
            return;
        
        no[i] = '0';
        solve(i + 1, no, st, ans);
        no[i] = '1';
        solve(i + 1, no, st, ans);
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end());
        string no(nums.size(), '.'), ans;
        solve(0, no, st, ans);
        return ans;
    }
};