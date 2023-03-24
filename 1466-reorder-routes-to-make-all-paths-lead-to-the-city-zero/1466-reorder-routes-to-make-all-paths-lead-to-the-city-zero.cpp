class Solution {
public:
    void dfs(int cur, int par, vector<vector<pair<int, int>>> &gr, int &ans)
    {
        for(auto &[child, sign] : gr[cur])
        {
            if(child != par)
            {
                ans += sign;
                dfs(child, cur, gr, ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> gr(n);
        for(auto &connection : connections){
            gr[connection[0]].push_back({connection[1], 1});
            gr[connection[1]].push_back({connection[0], 0});
        }
        int ans = 0;
        dfs(0, -1, gr, ans);
        return ans;
    }
};