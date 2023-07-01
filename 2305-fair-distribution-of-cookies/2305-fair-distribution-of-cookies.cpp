class Solution {
public:
    
    int solve(int i, int zeroCount, vector<int> &children, vector<int> &cookies)
    {
        if(cookies.size() - i < zeroCount)
            return INT_MAX;
        
        if(i == cookies.size())
            return *max_element(children.begin(), children.end());
        
        int ans = INT_MAX;
        for(int &child : children)
        {
            if(child == 0)
                zeroCount--;
            child += cookies[i];
            ans = min(ans, solve(i + 1, zeroCount, children, cookies));
            child -= cookies[i];
            if(child == 0)
                zeroCount++;
        }
        return ans;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k);
        return solve(0, k, children, cookies);
    }
};