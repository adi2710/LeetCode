class Solution {
public:
    
    void solve(int n, int &k, string &cur, string &ans) {
        if(n == 0) {
            k--;
            if(k == 0)
                ans = cur;
            return;
        }
        
        if(k == 0)
            return;
        
        for(char ch = 'a'; ch <= 'c'; ch++) {
            if(cur.empty() || cur.back() != ch) {
                cur.push_back(ch);
                solve(n - 1, k, cur, ans);
                cur.pop_back();
            }
        }
    }
    
    string getHappyString(int n, int k) {
        string ans, cur;
        solve(n, k, cur, ans);
        return ans;
    }
};