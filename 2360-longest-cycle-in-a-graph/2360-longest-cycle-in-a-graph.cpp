class Solution {
public:
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), ans = -1, timer = 0;
        vector<int> vis(n, -1);
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == -1)
            {
                int node = i, start_time = timer;
                while(node != -1 && vis[node] == -1)
                {
                    vis[node] = timer++;
                    node = edges[node];
                }
                if(node != -1 && start_time <= vis[node])
                    ans = max(ans, timer - vis[node]);
            }
        }
        return ans;
    }
};