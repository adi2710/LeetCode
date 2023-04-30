class dsu{
public:
    int comp;
    vector<int> par, rank;
    dsu(int n)
    {
        comp = n - 1;
        par.resize(n);
        rank.resize(n, 1);
        iota(par.begin(), par.end(), 0);
    }
    int find(int cur)
    {
        if(cur == par[cur])
            return cur;
        return par[cur] = find(par[cur]);
    }
    bool unite(int u, int v)
    {
        int p1 = find(u), p2 = find(v);
        if(p1 == p2)
            return false;
        if(rank[p1] == rank[p2])
        {
            par[p2] = p1;
            rank[p1]++;
        }
        else if(rank[p1] < rank[p2])
            par[p1] = p2;
        else
            par[p2] = p1;
        comp--;
        return true;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        dsu *alice = new dsu(n + 1), *bob = new dsu(n + 1);
        int cnt = 0;
        for(auto &edge : edges)
        {
            if(edge[0] == 3)
                cnt += bob -> unite(edge[1], edge[2]) | alice -> unite(edge[1], edge[2]);
        }
        for(auto &edge : edges)
        {
            if(edge[0] == 1)
                cnt += alice -> unite(edge[1], edge[2]);
            else if(edge[0] == 2)
                cnt += bob -> unite(edge[1], edge[2]);
        }
        if(alice -> comp == 1 && bob -> comp == 1)
            return edges.size() - cnt;
        return -1;
    }
};