class Solution {
public:
    
    void solve(int i, vector<int> &nums, vector<int> &ar, set<vector<int>> &st)
    {
        if(i == nums.size())
        {
            if(ar.size() > 1)
                st.insert(ar);
            return;
        }
        if(ar.empty() || ar.back() <= nums[i])
        {
            ar.push_back(nums[i]);
            solve(i + 1, nums, ar, st);
            ar.pop_back();
        }
        solve(i + 1, nums, ar, st);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> ar;
        solve(0, nums, ar, st);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};