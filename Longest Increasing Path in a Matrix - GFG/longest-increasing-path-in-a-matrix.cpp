//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int dp[1001][1001];
    vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};

    int findLIP(int r, int c, vector<vector<int>> &mat)
    {   
        if(dp[r][c] != -1)
            return dp[r][c];
        
        int ans = 1;
        for(int i = 0; i < 4; i++)
        {
            int row = dx[i] + r, col = dy[i] + c;
            if(row < 0 || col < 0 || row >= mat.size() || col >= mat[0].size() || mat[row][col] <= mat[r][c])
                continue;
            ans = max(ans, 1 + findLIP(row, col, mat));
        }
        return dp[r][c] = ans; 
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int r = 0; r < matrix.size(); r++)
        {
            for(int c = 0; c < matrix[0].size(); c++)
                ans = max(ans, findLIP(r, c, matrix));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends