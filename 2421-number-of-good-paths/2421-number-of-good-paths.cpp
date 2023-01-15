class Solution {
public:
    
    int find(int cur, vector<int> &par)
    {
        while(cur != par[cur])
        {
            par[cur] = par[par[cur]];
            cur = par[cur];
        }
        return cur;
    }
    
    void performUnion(int u, int v, vector<int> &par, vector<int> &rank)
    {
        int par_u = find(u, par), par_v = find(v, par);
        if(par_u == par_v)
            return;
        if(rank[par_u] == rank[par_v])
        {
            rank[par_u] += rank[par_v];
            par[par_v] = par_u;
        }
        else if(rank[par_u] > rank[par_v])
            par[par_v] = par_u;
        else
            par[par_u] = par_v;
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size(), ans = 0;
        vector<vector<int>> gr(n);
        vector<int> par(n), rank(n, 1);
        iota(par.begin(), par.end(), 0);
        for(auto &edge : edges)
        {
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        
        map<int, vector<int>> mp;
        for(int i = 0; i < n; i++)
            mp[vals[i]].push_back(i);
        
        for(auto &[val, nodes] : mp)
        {
            for(int node : nodes)
            {
                for(int adj : gr[node])
                {
                    if(vals[node] >= vals[adj])
                        performUnion(node, adj, par, rank);
                }
            }
            unordered_map<int, int> group;
            for(int node : nodes)
                group[find(node, par)]++;
            for(auto &[node, count] : group)
                ans += count * (count + 1) / 2;
        }
        return ans;
    }
};