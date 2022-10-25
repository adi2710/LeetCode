class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        vector<vector<bool>> vis(2, vector<bool> (6000));
        for(int forbid : forbidden)
            vis[0][forbid] = vis[1][forbid] = true;
        queue<pair<int, bool>> q;
        q.push({0, false});
        vis[0][0] = vis[1][0] = true;
        int ans = 0;
        while(!q.empty())
        {
            for(int i = q.size(); i >= 1; i--)
            {
                auto [pos, flag] = q.front();
                q.pop();
                if(pos == x)
                    return ans;
                int forward = pos + a, backward = pos - b;
                if(forward < 6000 && !vis[0][forward])
                {
                    q.push({forward, false});
                    vis[0][forward] = true;
                }
                if(!flag && backward >= 0 && !vis[1][backward])
                {
                    q.push({backward, true});
                    vis[1][backward] = true;
                }
            }
            ans++;
        }
        return -1;
    }
};