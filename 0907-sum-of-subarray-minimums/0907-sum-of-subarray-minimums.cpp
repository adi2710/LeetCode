class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int ans = 0;
        const int MOD = 1e9 + 7;
        stack<int> st;
        st.push(-1);
        arr.push_back(0);
        for(int i = 0; i < arr.size(); i++)
        {
            while(st.size() > 1 && arr[st.top()] >= arr[i])
            {
                int pos = st.top();
                st.pop();
                int sum = (pos - st.top()) * (i - pos);
                ans = (1ll * ans + 1ll * sum * arr[pos]) % MOD;
            }
            st.push(i);
        }
        return ans;
    }
};