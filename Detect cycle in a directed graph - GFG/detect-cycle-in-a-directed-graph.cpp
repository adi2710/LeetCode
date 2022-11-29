//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    bool dfs(int cur, vector<int> &vis, vector<int> adj[])
    {
        vis[cur] = 1;
        bool cycle = false;
        for(int child : adj[cur])
        {
            if(vis[child] == 2)
                continue;
            if(vis[child] == 1)
                return true;
            cycle = cycle || dfs(child, vis, adj);
        }
        vis[cur] = 2;
        return cycle;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V);
        bool ans = false;
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
                ans = ans || dfs(i, vis, adj);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends