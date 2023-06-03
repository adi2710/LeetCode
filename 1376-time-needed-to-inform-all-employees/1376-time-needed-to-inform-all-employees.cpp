class Solution {
public:
    
    void dfs(int cur, int par, int time, int &ans, vector<vector<int>> &gr, vector<int> &informTime)
    {
        for(int child : gr[cur])
        {
            if(child == par)
                continue;
            dfs(child, cur, time + informTime[cur], ans, gr, informTime);
        }
        ans = max(ans, time);
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> gr(n);
        for(int i = 0; i < n; i++)
        {
            if(i == headID)
                continue;
            gr[manager[i]].push_back(i);
        }
        int ans = 0;
        dfs(headID, -1, 0, ans, gr, informTime);
        return ans;
    }
};