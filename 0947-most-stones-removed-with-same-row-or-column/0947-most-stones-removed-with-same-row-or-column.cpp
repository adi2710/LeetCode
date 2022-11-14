class Solution {
public:
    
    int dfs(int cur, vector<bool> &vis, vector<vector<int>> &gr)
    {
        vis[cur] = 1;
        int cnt = 1;
        for(int adj : gr[cur])
        {
            if(vis[adj])
                continue;
            cnt += dfs(adj, vis, gr);
        }
        return cnt;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> gr(n);
        vector<bool> vis(n);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    gr[i].push_back(j);
                    gr[j].push_back(i);
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
                ans += dfs(i, vis, gr) - 1;
        }
        return ans;
    }
};