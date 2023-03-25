class Solution {
public:
    
    int dfs(int cur, vector<bool> &vis, vector<vector<int>> &gr)
    {
        vis[cur] = true;
        int cnt = 1;
        for(int adj : gr[cur])
        {
            if(!vis[adj])
                cnt += dfs(adj, vis, gr);
        }
        return cnt;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        int prev_cnt = 0;
        vector<bool> vis(n);
        vector<vector<int>> gr(n);
        for(auto edge : edges)
        {
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                int cur_cnt = dfs(i, vis, gr);
                ans += 1ll * prev_cnt * cur_cnt;
                prev_cnt += cur_cnt;
            }
        }
        return ans;
    }
};