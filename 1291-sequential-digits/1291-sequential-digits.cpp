class Solution {
public:
    
    void solve(int num, int &low, int &high, vector<int> &ans) {
        if(num > high)
            return;
        if(num >= low)
            ans.push_back(num);
        int lastDig = num % 10;
        if(lastDig == 9)
            return;
        solve(num * 10 + lastDig + 1, low, high, ans);
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i = 1; i <= 9; i++)
            solve(i, low, high, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};