class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> vis(n, vector<int> (m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        vis[0][0] = 0;
        pq.push({0, 0, 0});
        
        vector<pair<int, int>> dx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!pq.empty())
        {
            int r = pq.top()[1], c = pq.top()[2], effort = vis[r][c];
            pq.pop();
            for(auto x : dx)
            {
                int row = r + x.first, col = c + x.second;
                
                if(row < 0 || row >= n || col < 0 || col >= m || vis[row][col] <= max(abs(heights[r][c] - heights[row][col]), effort))
                    continue;
                
                vis[row][col] = max(abs(heights[r][c] - heights[row][col]), effort);
                pq.push({vis[row][col], row, col});
            }
        }
        
        return vis[n - 1][m - 1];
    }
};