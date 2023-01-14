class Solution {
public:
    
    int find(int cur, vector<int> &par)
    {
        while(par[cur] != cur)
        {
            par[cur] = par[par[cur]];
            cur = par[cur];
        }
        return cur;
    }
    
    bool unite(int u, int v, vector<int> &par)
    {
        int p1 = find(u, par), p2 = find(v, par);
        if(p1 == p2)
            return false;
        if(p1 < p2)
            par[p2] = p1;
        else
            par[p1] = p2;
        return true;
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> par(26);
        iota(par.begin(), par.end(), 0);
        for(int i = 0; i < s1.size(); i++)
            unite(s1[i] - 'a', s2[i] - 'a', par);
        string ans;
        for(char ch : baseStr)
            ans.push_back(find(ch - 'a', par) + 'a');
        return ans;
    }
};