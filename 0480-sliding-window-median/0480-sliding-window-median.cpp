class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<int> st;
        for(int l = 0, r = 0; r < nums.size(); r++)
        {
            st.insert(nums[r]);
            if(r >= k - 1)
            {
                auto mid = st.begin();
                advance(mid, k / 2);
                if(k & 1)
                    ans.push_back(*mid);
                else
                    ans.push_back((1ll * *mid + *(--mid)) / 2.0);
                auto it = st.find(nums[l]);
                st.erase(it);
                l++;
            }
        }
        return ans;
    }
};