//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &grid){
        // Code here
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool> (m));
        vector<vector<int>> ans(n, vector<int> (m));
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
            {
                if(grid[r][c] == 'W')
                {
                    q.push({r, c});
                    vis[r][c] = 1;
                }
                else if(grid[r][c] == 'H')
                    ans[r][c] = -1;
                else if(grid[r][c] == 'N')
                    vis[r][c] = 1;
            }
        }
        vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        int dis = 0;
        while(!q.empty())
        {
            dis++;
            for(int i = q.size(); i >= 1; i--)
            {
                int r = q.front().first, c = q.front().second;
                q.pop();
                for(int j = 0; j < 4; j++)
                {
                    int row = r + dx[j], col = c + dy[j];
                    if(row < 0 || row >= n || col < 0 || col >= m || vis[row][col])
                        continue;
                    if(grid[row][col] == 'H')
                        ans[row][col] = dis * 2;
                    q.push({row, col});
                    vis[row][col] = 1;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends