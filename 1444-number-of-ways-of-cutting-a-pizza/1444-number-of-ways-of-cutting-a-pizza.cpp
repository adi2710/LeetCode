class Solution {
public:
    const int MOD = 1e9 + 7;
    bool checkApple(int sr, int sc, int er, int ec, vector<string> &pizza)
    {
        for(int r = sr; r <= er; r++)
        {
            for(int c = sc; c <= ec; c++)
            {
                if(pizza[r][c] == 'A')
                    return true;
            }
        }
        return false;
    }
    
    int solve(int r, int c, int k, vector<string> &pizza, vector<vector<vector<int>>> &dp)
    {
        if(k == 1)
            return checkApple(r, c, pizza.size() - 1, pizza[0].size() - 1, pizza);
        if(k == 0 || r == pizza.size() || c == pizza[0].size())
            return 0;
        if(dp[r][c][k] != -1)
            return dp[r][c][k];
        int ans = 0;
        for(int er = r; er < pizza.size(); er++){
            if(checkApple(r, c, er, pizza[0].size() - 1, pizza))
                ans = (1ll * ans + solve(er + 1, c, k - 1, pizza, dp)) % MOD;
        }
        for(int ec = c; ec < pizza[0].size(); ec++){
            if(checkApple(r, c, pizza.size() - 1, ec, pizza))
                ans = (1ll * ans + solve(r, ec + 1, k - 1, pizza, dp)) % MOD;
        }
        return dp[r][c][k] = ans;
    }
    
    int ways(vector<string>& pizza, int k) {
        vector<vector<vector<int>>> dp(pizza.size() + 1, vector<vector<int>>(pizza[0].size() + 1, vector<int> (k + 1, -1)));
        return solve(0, 0, k, pizza, dp);
    }
};