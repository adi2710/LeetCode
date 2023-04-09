class Solution {
public:
    
    void dfs(int cur, vector<int> &vis, vector<vector<int>> &dp, vector<vector<int>> &gr, string &colors, int &ans)
    {
        vis[cur] = 1;
        for(int x : gr[cur])
        {
            if(vis[x] == 1)
                ans = -1;
            else if(!vis[x])
                dfs(x, vis, dp, gr, colors, ans);
        }
        vis[cur] = 2;
        dp[cur][colors[cur] - 'a']++;
        if(!gr[cur].empty())
        {
            vector<int> new_dp(26);
            for(int x : gr[cur])
            {
                for(int i = 0; i < 26; i++)
                    new_dp[i] = max(new_dp[i], dp[cur][i] + dp[x][i]);
            }
            for (int i = 0; i < 26; i++)
                dp[cur][i] = new_dp[i];
        }
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), ans = 0;
        vector<vector<int>> dp(n, vector<int> (26)), gr(n);
        vector<int> vis(n);
        for(auto &edge : edges)
            gr[edge[0]].push_back(edge[1]);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, dp, gr, colors, ans);
                if(ans == -1)
                    return -1;
                ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
            }
        }
        return ans;
    }
};