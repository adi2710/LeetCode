class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vis(n, vector<int> (m, -1));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0){
                    q.push({i, j});
                    vis[i][j] = 0;
                }
            }
        }
        vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        int ans = 0;
        while(!q.empty())
        {
            ans++;
            for(int i = q.size(); i >= 1; i--)
            {
                auto [r, c] = q.front();
                q.pop();
                for(int j = 0; j < 4; j++)
                {
                    int row = r + dx[j], col = c + dy[j];
                    if(row < 0 || row >= n || col < 0 || col >= m || vis[row][col] != -1)
                        continue;
                    vis[row][col] = ans;
                    q.push({row, col});
                }
            }
        }
        return vis;
    }
};