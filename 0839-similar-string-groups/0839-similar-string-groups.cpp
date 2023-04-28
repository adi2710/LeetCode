class Solution {
public:
    int find(int cur, vector<int> &par)
    {
        if(par[cur] == cur)
            return cur;
        return par[cur] = find(par[cur], par);
    }
    
    void unite(int u, int v, vector<int> &par, vector<int> &rank, int &comp)
    {
        int p1 = find(u, par), p2 = find(v, par);
        if(p1 == p2)
            return;
        if(rank[p1] == rank[p2])
        {
            par[p2] = p1;
            rank[p1]++;
        }
        else if(rank[p1] > rank[p2])
            par[p2] = p1;
        else
            par[p1] = p2;
        comp--;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(), comp = n;
        vector<int> par(n), rank(n);
        iota(par.begin(), par.end(), 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int cnt = 0;
                for(int k = 0; k < m; k++)
                {
                    if(strs[i][k] != strs[j][k])
                       cnt++;
                    if(cnt > 2)
                        break;
                }
                if(cnt == 0 || cnt == 2)
                    unite(i, j, par, rank, comp);
            }
        }
        return comp;
    }
};