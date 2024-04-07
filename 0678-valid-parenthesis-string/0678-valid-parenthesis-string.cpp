class Solution {
public:
    
    bool check(int i, int open, string &s, vector<vector<int>> &dp) {
        if(i == s.size()) {
            return open == 0;
        }
        
        if(open < 0)
            return false;
        
        if(dp[i][open] != -1)
            return dp[i][open];
        
        if(s[i] == '*') {
            if(open == 0)
                return dp[i][open] = check(i + 1, open + 1, s, dp) || check(i + 1, open, s, dp);
            return dp[i][open] = check(i + 1, open, s, dp) || check(i + 1, open + 1, s, dp) || check(i + 1, open - 1, s, dp);
        }
        
        return dp[i][open] = check(i + 1, s[i] == '(' ? open + 1 : open - 1, s, dp);
    }
    
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size(), vector<int> (s.size() + 1, -1));
        return check(0, 0, s, dp);
    }
};