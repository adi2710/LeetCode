class Solution {
public:
    
    int find(int cur, vector<int> &par)
    {
        if(par[cur] == cur)
            return cur;
        return par[cur] = find(par[cur], par);
    }
    
    void unite(int u, int v, vector<int> &rank, vector<int> &par, int &comp)
    {
        int par_u = find(u, par), par_v = find(v, par);
        if(par_u == par_v)
            return;
        comp--;
        if(rank[par_u] == rank[par_v])
        {
            par[par_v] = par_u;
            rank[par_u]++;
        }
        else if(rank[par_u] > rank[par_v])
            par[par_v] = par_u;
        else
            par[par_u] = par_v;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int comp = n;
        vector<int> par(n), rank(n, 1);
        iota(par.begin(), par.end(), 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j])
                    unite(i, j, rank, par, comp);
            }
        }
        return comp;
    }
};