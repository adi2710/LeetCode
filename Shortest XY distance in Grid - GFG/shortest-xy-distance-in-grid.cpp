//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
        queue<pair<int, int>> q;
        for(int r = 0; r < N; r++)
        {
            for(int c = 0; c < M; c++)
            {
                if(grid[r][c] == 'X')
                {
                    q.push({r, c});
                }
            }
        }
        int ans = 0;
        vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, 1, -1};
        while(!q.empty())
        {
            ans++;
            for(int i = q.size(); i >= 1; i--)
            {
                int r = q.front().first, c = q.front().second;
                q.pop();
                for(int j = 0; j < 4; j++)
                {
                    int new_r = r + dx[j], new_c = c + dy[j];
                    if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= M)
                        continue;
                    if(grid[new_r][new_c] == 'Y')
                        return ans;
                    else if(grid[new_r][new_c] == 'O')
                    {
                        q.push({new_r, new_c});
                        grid[new_r][new_c] = 'X';
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends