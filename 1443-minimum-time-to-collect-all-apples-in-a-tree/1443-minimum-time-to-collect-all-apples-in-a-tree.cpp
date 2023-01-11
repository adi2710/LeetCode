class Solution {
public:
    
    int dfs(int cur, int par, vector<vector<int>> &gr, vector<bool> &hasApple)
    {
        int dis = 0;
        for(int child : gr[cur])
        {
            if(child == par)
                continue;
            dis += dfs(child, cur, gr, hasApple);
        }
        if(hasApple[cur] || dis > 0)
            return dis + 2;
        return 0;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> gr(n);
        for(auto &edge : edges)
        {
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        int ans = dfs(0, 0, gr, hasApple);
        if(ans > 0)
            ans -= 2;
        return ans;
    }
};