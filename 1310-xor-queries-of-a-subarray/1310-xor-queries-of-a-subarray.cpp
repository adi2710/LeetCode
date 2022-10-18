class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pre(n + 1);
        for(int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] ^ arr[i - 1];
        vector<int> ans;
        for(auto &query : queries)
        {
            int l = query[0], r = query[1] + 1, xorSum = pre[r] ^ pre[l];
            ans.push_back(xorSum);
        }
        return ans;
    }
};