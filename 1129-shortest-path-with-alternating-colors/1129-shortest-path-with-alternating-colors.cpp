class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> gr(n);
        for(auto edge : redEdges)
            gr[edge[0]].push_back({edge[1], 0});
        for(auto edge : blueEdges)
            gr[edge[0]].push_back({edge[1], 1});
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int> (2));
        vector<int> ans(n, -1);
        q.push({0, -1});
        vis[0][0] = vis[0][1] = true;
        ans[0] = 0;
        int steps = 0;
        while(!q.empty())
        {
            steps++;
            for(int i = q.size(); i >= 1; i--)
            {
                auto [cur, prevCol] = q.front();
                q.pop();
                for(auto &[adj, col] : gr[cur])
                {
                    if(!vis[adj][col] && col != prevCol)
                    {
                        vis[adj][col] = true;
                        q.push({adj, col});
                        if(ans[adj] == -1)
                            ans[adj] = steps;
                    }
                }
            }
        }
        return ans;
    }
};