class Solution {
public:
    
    void solve(int i, int n, vector<int> &v, vector<bool> &vis, vector<int> &ans)
    {
        if(i == (1 << n)){
            if((v.back() & (v.back() - 1)) == 0)
                ans = v;
            return;
        }
        
        if(!ans.empty())
            return;
        
        int num = v.back();
        for(int bit = 0; bit <= 15; bit++)
        {
            int mask = 1 << bit;
            if(num & mask)
            {
                int no = num & ~mask;
                if(no < (1 << n) && !vis[no])
                {
                    vis[no] = 1;
                    v.push_back(no);
                    solve(i + 1, n, v, vis, ans);
                    v.pop_back();
                    vis[no] = 0;
                }
            }
            else if((num & mask) == 0)
            {
                int no = num | mask;
                if(no < (1 << n) && !vis[no])
                {
                    vis[no] = 1;
                    v.push_back(no);
                    solve(i + 1, n, v, vis, ans);
                    v.pop_back();
                    vis[no] = 0;
                }
            }
        }
    }
    
    vector<int> grayCode(int n) {
        vector<int> v = {0}, ans;
        vector<bool> vis(1 << n);
        vis[0] = 1;
        solve(1, n, v, vis, ans);
        return ans;
    }
};