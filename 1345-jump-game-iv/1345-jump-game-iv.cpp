class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);
        queue<int> q;
        vector<bool> vis(n);
        q.push(0);
        vis[0] = 1;
        while(!q.empty())
        {
            for(int i = q.size(); i >= 1; i--)
            {
                int cur = q.front();
                q.pop();
                if(cur == n - 1)
                    return ans;
                vector<int> &pos = mp[arr[cur]];
                pos.push_back(cur - 1);
                pos.push_back(cur + 1);
                for(int adj : pos)
                {
                    if(adj >= 0 && adj < n && !vis[adj])
                    {
                        q.push(adj);
                        vis[adj] = 1;
                    }
                }
                pos.clear();
            }
            ans++;
        }
        return -1;
    }
};