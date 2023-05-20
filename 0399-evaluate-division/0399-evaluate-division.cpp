class Solution {
public:
    
    double dfs(string &cur, string &end, unordered_set<string> &vis, unordered_map<string, vector<pair<string, double>>> &mp)
    {
        double ans = -1.0;
        vis.insert(cur);
        if(mp.find(cur) != mp.end() && cur == end)
            return 1.0;
        for(auto &child : mp[cur])
        {
            if(vis.find(child.first) != vis.end())
                continue;
            double prod = dfs(child.first, end, vis, mp);
            if(prod > 0){
                ans = child.second * prod;
                break;
            }
        }
        return ans;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mp;
        for(int i = 0; i < equations.size(); i++)
        {
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        vector<double> ans;
        unordered_set<string> vis;
        for(auto &query : queries)
        {
            vis.clear();
            ans.push_back(dfs(query[0], query[1], vis, mp));
        }
        return ans;
    }
};