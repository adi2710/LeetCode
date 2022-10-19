class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int xorSum = 0, n = encoded.size();
        for(int i = 1; i <= n + 1; i++)
            xorSum ^= i;
        for(int i = 1; i < n; i += 2)
            xorSum ^= encoded[i];
        vector<int> ans(n + 1);
        ans[0] = xorSum;
        for(int i = 0; i < n; i++)
            ans[i + 1] = ans[i] ^ encoded[i];
        return ans;
    }
};