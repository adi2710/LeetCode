class Solution {
public:
    
    void dfs(int cur, vector<bool> &vis, vector<vector<int>> &isConnected)
    {
        vis[cur] = 1;
        for(int i = 0; i < isConnected.size(); i++)
        {
            if(isConnected[cur][i] && !vis[i])
                dfs(i, vis, isConnected);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<bool> vis(n);
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                dfs(i, vis, isConnected);
                ans++;
            }
        }
        return ans;
    }
};