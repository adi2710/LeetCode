class Solution {
public:
    
    bool dfs(int cur, int dest, vector<bool> &vis, vector<vector<int>> &gr)
    {
        vis[cur] = true;
        if(cur == dest)
            return true;
        bool pathExists = false;
        for(int adj : gr[cur])
        {
            if(vis[adj])
                continue;
            pathExists = pathExists || dfs(adj, dest, vis, gr);
        }
        return pathExists;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> gr(n);
        vector<bool> vis(n);
        for(auto &edge : edges)
        {
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        return dfs(source, destination, vis, gr);
    }
};