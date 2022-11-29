class Solution {
public:
    
    void dfs(int cur, vector<bool> &vis, vector<vector<bool>> &gr)
    {
        if(vis[cur])
            return;
        vis[cur] = true;
        for(int adj = 0; adj < gr.size(); adj++)
        {
            if(gr[cur][adj])
            {
                dfs(adj, vis, gr);
                for(int j = 0; j < gr.size(); j++)
                    gr[cur][j] = gr[cur][j] || gr[adj][j];
            }
        }
    }
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> gr(numCourses, vector<bool> (numCourses));
        vector<bool> vis(numCourses);
        for(auto course : prerequisites)
            gr[course[0]][course[1]] = true;
        for(int i = 0; i < numCourses; i++)
            dfs(i, vis, gr);
        vector<bool> ans;
        for(auto query : queries)
            ans.push_back(gr[query[0]][query[1]]);
        return ans;
    }
};