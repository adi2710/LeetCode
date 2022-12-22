class Solution {
public:
    
    void dfs(int cur, int par, vector<int> &count, vector<int> &ans, vector<vector<int>> &gr)
    {
        for(int child : gr[cur])
        {
            if(child == par)
                continue;
            dfs(child, cur, count, ans, gr);
            count[cur] += count[child];
            ans[cur] += ans[child] + count[child];
        }
    }
    
    void dfs2(int cur, int par, int N, vector<int> &count, vector<int> &ans, vector<vector<int>> &gr)
    {
        for(int child : gr[cur])
        {
            if(child == par)
                continue;
            ans[child] = ans[cur] - count[child] + (N - count[child]);
            dfs2(child, cur, N, count, ans, gr);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> count(n, 1), ans(n, 0);
        vector<vector<int>> gr(n);
        for(auto &edge : edges)
        {
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        dfs(0, 0, count, ans, gr);
        dfs2(0, 0, n, count, ans, gr);
        return ans;
    }
};