class Solution {
public:
    
    bool dfs(int cur, vector<int> &col, vector<vector<int>> &gr)
    {
        bool ans = true;
        for(int adj : gr[cur])
        {
            if(col[adj] == col[cur])
                return false;
            if(col[adj] == 0)
            {
                col[adj] = 3 - col[cur];
                ans = ans && dfs(adj, col, gr);
            }
        }
        return ans;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n);
        bool ans = true;
        for(int i = 0; i < n; i++)
        {
            if(col[i] == 0)
            {
                col[i] = 1;
                ans = ans && dfs(i, col, graph);
            }
        }
        return ans;
    }
};