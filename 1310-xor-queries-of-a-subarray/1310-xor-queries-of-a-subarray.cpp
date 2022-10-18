class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<vector<int>> pre(n + 1, vector<int> (31));
        for(int i = 1; i <= n; i++)
        {
            for(int bit = 0; bit <= 30; bit++)
            {
                int mask = 1 << bit;
                pre[i][bit] = pre[i - 1][bit] + ((arr[i - 1] & mask) == 0 ? 0 : 1);
            }
        }
        vector<int> ans;
        for(auto &query : queries)
        {
            int l = query[0], r = query[1] + 1, xorSum = 0;
            for(int bit = 0; bit <= 30; bit++)
            {
                int cnt = pre[r][bit] - pre[l][bit];
                if(cnt & 1)
                    xorSum |= (1 << bit);
            }
            ans.push_back(xorSum);
        }
        return ans;
    }
};