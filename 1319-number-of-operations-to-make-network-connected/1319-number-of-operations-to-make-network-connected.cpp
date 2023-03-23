class Solution {
public:
    
    void dfs(int cur, vector<bool> &vis, vector<vector<int>> &gr)
    {
        vis[cur] = 1;
        for(int adj : gr[cur])
        {
            if(vis[adj])
                continue;
            dfs(adj, vis, gr);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)
            return -1;
        int comp = 0;
        vector<bool> vis(n);
        vector<vector<int>> gr(n);
        for(auto &connection : connections)
        {
            gr[connection[0]].push_back(connection[1]);
            gr[connection[1]].push_back(connection[0]);
        }
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                comp++;
                dfs(i, vis, gr);
            }
        }
        return comp - 1;
    }
};