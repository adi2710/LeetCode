class Solution {
public:
    
    int dfs(int cur, int par, int seats, long long &ans, vector<vector<int>> &gr)
    {
        int siz = 1;
        for(int adj : gr[cur])
        {
            if(adj != par)
                siz += dfs(adj, cur, seats, ans, gr);
        }
        ans += (siz + seats - 1) / seats;
        return siz;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long ans = 0;
        int n = roads.size();
        vector<vector<int>> gr(n + 1);
        for(auto road : roads){
            gr[road[0]].push_back(road[1]);
            gr[road[1]].push_back(road[0]);
        }
        for(int adj : gr[0])
            dfs(adj, 0, seats, ans, gr);
        return ans;
    }
};