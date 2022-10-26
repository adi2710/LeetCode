class Solution {
public:
    
    bool dfs(int cur, stack<int> &st, vector<int> &vis, vector<vector<int>> &gr)
    {
        vis[cur] = 1;
        bool fl = true;
        for(int adj : gr[cur])
        {
            if(vis[adj] == 1)
                return false;
            else if(!vis[adj])
                fl = fl && dfs(adj, st, vis, gr);
        }
        vis[cur] = 2;
        st.push(cur);
        return fl;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses);
        vector<int> ans;
        vector<vector<int>> gr(numCourses);
        for(auto &edge : prerequisites)
            gr[edge[1]].push_back(edge[0]);
        stack<int> st;
        bool fl = true;
        for(int i = 0; i < numCourses; i++)
        {
            if(!vis[i])
                fl = fl && dfs(i, st, vis, gr);
        }
        if(!fl)
            return ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};