class Solution {
public:
    
    int solve(int i, vector<int> &children, vector<int> &cookies)
    {
        if(i == cookies.size())
            return *max_element(children.begin(), children.end());
        
        int ans = INT_MAX;
        for(int &child : children)
        {
            child += cookies[i];
            ans = min(ans, solve(i + 1, children, cookies));
            child -= cookies[i];
        }
        return ans;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k);
        return solve(0, children, cookies);
    }
};