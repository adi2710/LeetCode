class Solution {
public:
    
    vector<int> dfs(int cur, int par, string &labels, vector<vector<int>> &gr, vector<int> &ans)
    {
        vector<int> freq(26);
        for(int x : gr[cur])
        {
            if(x == par)
                continue;
            vector<int> childFreq = dfs(x, cur, labels, gr, ans);
            for(int i = 0; i < 26; i++)
                freq[i] += childFreq[i];
        }
        freq[labels[cur] - 'a']++; 
        ans[cur] = freq[labels[cur] - 'a'];
        return freq;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string &labels) {
        vector<int> ans(n);
        vector<vector<int>> gr(n);
        for(auto &edge : edges)
        {
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        dfs(0, 0, labels, gr, ans);
        return ans;
    }
};