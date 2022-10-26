class Solution {
    
    int bfs(vector<vector<int>> &forest, int sr, int sc, int dr, int dc)
    {
        int n = forest.size(), m = forest[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<vector<bool>> vis(n, vector<bool> (m));
        vis[sr][sc] = true;
        vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        int step = 0;
        while(!q.empty())
        {
            for(int i = q.size(); i >= 1; i--)
            {
                auto [r, c] = q.front();
                q.pop();
                if(r == dr && c == dc)
                    return step;
                for(int idx = 0; idx < 4; idx++)
                {
                    int row = r + dx[idx], col = c + dy[idx];
                    if(row < 0 || row >= n || col < 0 || col >= m || forest[row][col] == 0 || vis[row][col])
                        continue;
                    q.push({row, col});
                    vis[row][col] = true;
                }
            }
            step++;
        }
        return -1;
    }
    
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int n = forest.size(), m = forest[0].size(), ans = 0;
        vector<pair<int, int>> trees;
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
            {
                if(forest[r][c] > 1)
                    trees.push_back({r, c});
            }
        }
        sort(trees.begin(), trees.end(), [&](const pair<int, int> &a, const pair<int, int> &b){
            return forest[a.first][a.second] < forest[b.first][b.second];
        });
        
        for(int i = 0, sr = 0, sc = 0; i < trees.size(); i++)
        {
            int minDist = bfs(forest, sr, sc, trees[i].first, trees[i].second);
            if(minDist == -1)
                return -1;
            ans += minDist;
            sr = trees[i].first;
            sc = trees[i].second;
        }
        return ans;
    }
};