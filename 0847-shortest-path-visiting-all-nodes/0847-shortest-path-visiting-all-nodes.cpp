class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1)
            return 0;
        vector<vector<bool>> vis(n, vector<bool> (1 << n));
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++)
        {
            q.push({i, 1 << i});
            vis[i][1 << i] = true;
        }
        
        int ans = 0, final_mask = (1 << n) - 1;
        while(!q.empty())
        {
            for(int i = q.size(); i >= 1; i--)
            {
                int node = q.front().first, mask = q.front().second;
                q.pop();
                
                if(mask == final_mask)
                    return ans;
                
                for(int adj : graph[node])
                {
                    int new_mask = mask | (1 << adj);
                    if(vis[adj][new_mask])
                        continue;
                    q.push({adj, new_mask});
                    vis[adj][new_mask] = true;
                }
            }
            ans++;
        }
        return ans;
    }
};