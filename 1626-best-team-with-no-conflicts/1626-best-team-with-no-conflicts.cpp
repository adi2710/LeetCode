class Solution {
public:
    
    int dp[1001][1001];
    
    int solve(int i, int mxAge, vector<vector<int>> &player){
        if(i == player.size())
            return 0;
        
        if(dp[i][mxAge] != -1)
            return dp[i][mxAge];
        
        int ans = 0;
        if(mxAge <= player[i][1])
            ans = max(ans, player[i][0] + solve(i + 1, player[i][1], player));
        ans = max(ans, solve(i + 1, mxAge, player));
        return dp[i][mxAge] = ans;
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> player(n, vector<int> (2));
        for(int i = 0; i < n; i++)
            player[i][0] = scores[i], player[i][1] = ages[i];
        sort(player.begin(), player.end());
        return solve(0, 0, player);
    }
};