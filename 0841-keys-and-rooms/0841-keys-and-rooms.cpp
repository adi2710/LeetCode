class Solution {
public:
    
    void dfs(int cur, vector<bool> &vis, vector<vector<int>> &rooms)
    {
        vis[cur] = true;
        for(int adj : rooms[cur])
        {
            if(vis[adj])
                continue;
            dfs(adj, vis, rooms);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size());
        dfs(0, vis, rooms);
        for(int i = 0; i < rooms.size(); i++)
        {
            if(!vis[i])
                return false;
        }
        return true;
    }
};