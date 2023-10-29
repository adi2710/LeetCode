class Solution {
public:
    
    int dfs(int cur, int power, vector<vector<int>> &gr, vector<int> &coins, int &k, vector<int> &par, vector<vector<int>> &dp){
        if(dp[cur][power] != -1)
            return dp[cur][power];
        int first = coins[cur] / (1 << power) - k;
        for(int child : gr[cur])
        {
            if(child == par[cur])
                continue;
            par[child] = cur;
            first += dfs(child, power, gr, coins, k, par, dp);
        }
        int second = coins[cur] / (1 << (power + 1));
        for(int child : gr[cur])
        {
            if(child == par[cur])
                continue;
            second += dfs(child, min(15, power + 1), gr, coins, k, par, dp);
        }
        return dp[cur][power] = max(first, second);
    }
    
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = edges.size();
        vector<vector<int>> gr(n + 1);
        for(auto edge : edges) {
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        vector<int> par(n + 1);
        vector<vector<int>> dp(n + 1, vector<int> (16, -1));
        return dfs(0, 0, gr, coins, k, par, dp);
    }
};