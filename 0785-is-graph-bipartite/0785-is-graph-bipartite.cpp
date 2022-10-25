class Solution {
public:
    
    bool dfs(int cur, vector<int> &col, vector<vector<int>> &gr)
    {
        bool ans = true;
        for(int adj : gr[cur])
        {
            if(col[cur] == col[adj])
                return false;
            if(col[adj] > 0)
                continue;
            col[adj] = 3 - col[cur];
            ans = ans && dfs(adj, col, gr);
        }
        return ans;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> col(graph.size());
        bool ans = true;
        for(int i = 0; i < graph.size(); i++)
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