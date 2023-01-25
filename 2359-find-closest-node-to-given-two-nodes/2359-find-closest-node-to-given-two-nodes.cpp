class Solution {
public:
    
    vector<int> dfs(vector<int> &edges, int node)
    {
        int n = edges.size();
        vector<int> dis(n, INT_MAX);
        dis[node] = 0;
        int cnt = 1;
        while(edges[node] != -1){
            if(dis[edges[node]] < INT_MAX)
                break;
            dis[edges[node]] = cnt++;
            node = edges[node];
        }
        return dis;
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dis1 = dfs(edges, node1), dis2 = dfs(edges, node2);
        int ans = INT_MAX, pos = -1;
        for(int i = 0; i < dis1.size(); i++){
            if(ans > max(dis1[i], dis2[i]))
            {
                ans = max(dis1[i], dis2[i]);
                pos = i;
            }
        }
        return pos;
    }
};