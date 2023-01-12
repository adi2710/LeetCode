class Solution {
public:
    
    void dfs(int cur, int par, string &labels, vector<vector<int>> &gr, vector<int> &freq, vector<int> &ans)
    {
        int temp = freq[labels[cur] - 'a'];
        freq[labels[cur] - 'a'] = 1;
        for(int x : gr[cur])
        {
            if(x == par)
                continue;
            dfs(x, cur, labels, gr, freq, ans);
        }
        ans[cur] = freq[labels[cur] - 'a'];
        freq[labels[cur] - 'a'] += temp;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string &labels) {
        vector<int> ans(n), freq(26);
        vector<vector<int>> gr(n);
        for(auto &edge : edges)
        {
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        dfs(0, 0, labels, gr, freq, ans);
        return ans;
    }
};