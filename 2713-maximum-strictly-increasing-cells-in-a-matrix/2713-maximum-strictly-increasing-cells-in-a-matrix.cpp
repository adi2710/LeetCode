class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> max_row(n), max_col(m);
        map<int, vector<pair<int, int>>> mp;
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
                mp[mat[r][c]].push_back({r, c});
        }
        int ans = 0;
        for(auto &[val, vec] : mp)
        {
            vector<int> temp;
            for(auto &[r, c] : vec){
                int cur = max(max_row[r], max_col[c]);
                temp.push_back(cur + 1);
                ans = max(ans, cur + 1);
            }
            int pos = 0;
            for(auto &[r, c] : vec){
                max_row[r] = max(max_row[r], temp[pos]);
                max_col[c] = max(max_col[c], temp[pos]);
                pos++;
            }
        }
        return ans;
    }
};