class Solution {
public:
    
    void bfs(int cur, vector<bool> &vis, vector<vector<int>> &isConnected)
    {
        vis[cur] = 1;
        queue<int> q;
        q.push(cur);
        while(!q.empty())
        {
            cur = q.front();
            q.pop();
            for(int i = 0; i < isConnected.size(); i++)
            {
                if(isConnected[cur][i] && !vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<bool> vis(n);
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                bfs(i, vis, isConnected);
                ans++;
            }
        }
        return ans;
    }
};