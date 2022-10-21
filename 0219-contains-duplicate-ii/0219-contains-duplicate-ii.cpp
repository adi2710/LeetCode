class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int j = 0, i = 0; i < nums.size(); i++)
        {
            if(st.find(nums[i]) != st.end())
                return true;
            st.insert(nums[i]);
            if(i >= k)
                st.erase(nums[j++]);
        }
        return false;
    }
};