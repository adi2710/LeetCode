class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int x : nums)
            freq[x]++;
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        for(auto &[num, cnt] : freq)
            bucket[cnt].push_back(num);
        vector<int> ans;
        for(int i = n; i >= 1 && k > 0; i--)
        {
            for(int j = 0; j < bucket[i].size() && k > 0; j++, k--)
                ans.push_back(bucket[i][j]);
        }
        return ans;
    }
};