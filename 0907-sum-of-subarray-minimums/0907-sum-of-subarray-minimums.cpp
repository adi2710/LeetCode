class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        arr.push_back(0);
        stack<int> st;
        st.push(-1);
        int ans = 0;
        const int MOD = 1e9 + 7;
        for(int i = 0; i < arr.size(); i++)
        {
            while(st.size() > 1 && arr[st.top()] >= arr[i])
            {
                int idx = st.top();
                st.pop();
                int lf = idx - st.top(), rt = i - idx;
                ans = (ans + 1ll * arr[idx] * lf * rt) % MOD;
            }
            st.push(i);
        }
        return ans;
    }
};