class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> ans;
        ans.push_back(poured);
        for(int i = 0; i < query_row; i++)
        {
            int n = ans.size();
            vector<double> v(n + 1);
            for(int j = 0; j < n; j++)
            {
                double overflow = ans[j] - 1 > 0 ? ans[j] - 1 : 0;
                v[j] += overflow / 2;
                v[j + 1] += overflow / 2;
            }
            ans = v;
        }
        return ans[query_glass] <= 1 ? ans[query_glass] : 1;
    }
};