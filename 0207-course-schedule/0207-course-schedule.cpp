class Solution {
public:
    
    bool isCyclic(int cur, vector<int> &vis, vector<vector<int>> &gr)
    {
        vis[cur] = 1;
        bool cycle = false;
        for(int adj : gr[cur])
        {
            if(vis[adj] == 2)
                continue;
            else if(vis[adj] == 1)
                return true;
            cycle = cycle || isCyclic(adj, vis, gr);
        }
        vis[cur] = 2;
        return cycle;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> gr(numCourses);
        vector<int> vis(numCourses);
        for(auto course : prerequisites)
            gr[course[1]].push_back(course[0]);
        bool ans = false;
        for(int i = 0; i < numCourses; i++)
        {
            if(!vis[i])
                ans = ans || isCyclic(i, vis, gr);
        }
        return !ans;
    }
};