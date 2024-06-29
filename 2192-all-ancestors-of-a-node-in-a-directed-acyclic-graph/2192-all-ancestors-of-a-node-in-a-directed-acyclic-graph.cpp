class Solution {
public:
    void dfs(int cur, vector<vector<int>> &gr, vector<unordered_set<int>> &ans, vector<bool> &vis) {
        vis[cur] = true;
        for(int child : gr[cur]) {
            ans[cur].insert(child);
            if(!vis[child])
                dfs(child, gr, ans, vis);
            ans[cur].insert(ans[child].begin(), ans[child].end());
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> gr(n);
        vector<unordered_set<int>> ans(n);
        vector<bool> vis(n);
        for(auto edge : edges) {
            gr[edge[1]].emplace_back(edge[0]);
        }
        for(int i = 0; i < n; i++) {
            if(!vis[i])
                dfs(i, gr, ans, vis);
        }
        vector<vector<int>> res(n);
        for(int i = 0; i < n; i++) {
            for(int x : ans[i]) {
                res[i].emplace_back(x);
            }
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
};