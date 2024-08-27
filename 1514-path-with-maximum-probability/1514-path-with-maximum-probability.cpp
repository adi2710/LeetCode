class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> gr(n);
        for(int i = 0; i < edges.size(); i++) {
            gr[edges[i][0]].push_back({edges[i][1], succProb[i]});
            gr[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        priority_queue<pair<double, int>> pq;
        vector<double> vis(n);
        
        pq.push({1.0, start_node});
        vis[start_node] = 1.0;
        
        while(!pq.empty()) {
            auto [_, cur] = pq.top();
            pq.pop();
            
            for(auto [adj, prob] : gr[cur]) {
                if(vis[adj] < vis[cur] * prob) {
                    vis[adj] = vis[cur] * prob;
                    pq.push({vis[adj], adj});
                }
            }
        }
        
        return vis[end_node];
    }
};