class Solution {
public:
    
    int find(int cur, vector<int> &par)
    {
        if(par[cur] == cur)
            return cur;
        return par[cur] = find(par[cur], par);
    }
    
    void unite(int u, int v, vector<int> &par, vector<int> &rank)
    {
        int p1 = find(u, par), p2 = find(v, par);
        if(p1 == p2)
            return;
        if(rank[p1] == rank[p2])
        {
            par[p2] = p1;
            rank[p1]++;
        }
        else if(rank[p1] < rank[p2])
            par[p1] = p2;
        else
            par[p2] = p1;
    }
    
    inline bool isConnected(int u, int v, vector<int> &par)
    {
        return find(u, par) == find(v, par);
    }
    
    static bool compare(const vector<int> &a, const vector<int> &b){
            return a[2] < b[2];
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<int> par(n), rank(n);
        iota(par.begin(), par.end(), 0);
        sort(edgeList.begin(), edgeList.end(), compare);
        for(int i = 0; i < queries.size(); i++)
            queries[i].push_back(i);
        sort(queries.begin(), queries.end(), compare);
        int idx = 0;
        vector<bool> ans(queries.size());
        for(auto query : queries)
        {
            int u = query[0], v = query[1], limit = query[2], pos = query[3]; 
            while(idx < edgeList.size() && edgeList[idx][2] < limit)
                unite(edgeList[idx][0], edgeList[idx][1], par, rank), idx++;
            ans[pos] = isConnected(u, v, par);
        }
        return ans;
    }
};