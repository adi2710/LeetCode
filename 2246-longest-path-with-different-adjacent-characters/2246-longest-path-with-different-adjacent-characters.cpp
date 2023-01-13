class Solution {
public:
    
    int dfs(int cur, int par, int &ans, string &s, vector<vector<int>> &gr)
    {
        int maxPath1 = 0, maxPath2 = 0;
        for(int child : gr[cur])
        {
            if(par == child)
                continue;
            int path = dfs(child, cur, ans, s, gr);
            if(s[child] != s[cur])
            {
                if(maxPath1 < path)
                {
                    maxPath2 = maxPath1;
                    maxPath1 = path;
                }
                else if(maxPath2 < path)
                    maxPath2 = path;
            }
        }
        ans = max(ans, maxPath1 + maxPath2 + 1);
        return maxPath1 + 1;
    }
    
    int longestPath(vector<int>& parent, string &s) {
        int n = s.size(), ans = 0;
        vector<vector<int>> gr(n);
        for(int i = 1; i < n; i++)
        {
            gr[i].push_back(parent[i]);
            gr[parent[i]].push_back(i);
        }
        dfs(0, 0, ans, s, gr);
        return ans;
    }
};