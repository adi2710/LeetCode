//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    bool dfs(int cur, int par, vector<bool> &vis, vector<int> adj[])
    {
        vis[cur] = true;
        bool cycle = false;
        for(int child : adj[cur])
        {
            if(child == par)
                continue;
            if(vis[child])
                return true;
            cycle = cycle || dfs(child, cur, vis, adj);
        }
        return cycle;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V);
        bool ans = false;
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
                ans = ans || dfs(i, i, vis, adj);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends