class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        int q = queries.size();
        vector<vector<int>> query(q);
        for(int i = 0; i < q; i++)
            query[i] = {queries[i], i};
        sort(query.begin(), query.end());
        int l = 0, r = 0;
        unordered_map<int, int> mp;
        vector<int> ans(q);
        for(auto quer : query)
        {
            int st = quer[0] - x, en = quer[0], idx = quer[1];
            while(r < logs.size() && logs[r][1] <= en)
                mp[logs[r][0]]++, r++;
            while(l < r && logs[l][1] < st)
            {
                mp[logs[l][0]]--;
                if(mp[logs[l][0]] == 0)
                    mp.erase(logs[l][0]);
                l++;
            }
            // cout << l << ' ' << r << endl;
            ans[idx] = n - mp.size();
        }
        return ans;
    }
};