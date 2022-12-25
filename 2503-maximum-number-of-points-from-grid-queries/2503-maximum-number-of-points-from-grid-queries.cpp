class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int curAns = 0, n = grid.size(), m = grid[0].size(), k = queries.size();
        
        vector<pair<int, int>> v(k);
        for(int i = 0; i < k; i++)
            v[i] = {queries[i], i};
        
        sort(v.begin(), v.end());
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({grid[0][0], 0, 0});
        grid[0][0] = 0;
        
        vector<int> ans(k), dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        
        for(auto &[query, idx] : v){
            while(!pq.empty())
            {
                auto [cur, row, col] = pq.top();
                if(cur >= query)
                    break;
                else
                {
                    pq.pop();
                    curAns++;
                }
                for(int i = 0; i < dx.size(); i++)
                {
                    int r = row + dx[i], c = col + dy[i];
                    if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0)
                        continue;
                    pq.push({grid[r][c], r, c});
                    grid[r][c] = 0;
                }
            }
            ans[idx] = curAns;
        }
        return ans;
    }
};