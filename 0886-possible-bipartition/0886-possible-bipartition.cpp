class Solution {
public:
    
    bool dfs(int cur, vector<int> &col, vector<vector<int>> &gr)
    {
        bool fl = true;
        for(int adj : gr[cur])
        {
            if(col[adj] == col[cur])
                return false;
            if(col[adj] == 0){
                col[adj] = 3 - col[cur];
                fl = fl && dfs(adj, col, gr);
            }
        }
        return fl;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> gr(n + 1);
        for(auto &x : dislikes)
        {
            gr[x[0]].push_back(x[1]);
            gr[x[1]].push_back(x[0]);
        }
        vector<int> col(n + 1);
        bool ans = true;
        for(int i = 1; i <= n; i++)
        {
            if(col[i] == 0){
                col[i] = 1;
                ans = ans && dfs(i, col, gr);
            }
        }
        return ans;
    }
};