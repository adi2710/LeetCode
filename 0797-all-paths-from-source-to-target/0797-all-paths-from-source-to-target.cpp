class Solution {
public:
    
    void dfs(int cur, int last, vector<vector<int>> &gr, vector<int> &v, vector<vector<int>> &ans)
    {
        if(cur == last)
        {
            ans.push_back(v);
            return;
        }
        for(int adj : gr[cur])
        {
            v.push_back(adj);
            dfs(adj, last, gr, v, ans);
            v.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> v = {0};
        vector<vector<int>> ans;
        dfs(0, graph.size() - 1, graph, v, ans);
        return ans;
    }
};