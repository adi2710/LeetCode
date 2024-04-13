class Solution {
public:
    
    int maxRectangle(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < n; i++)
        {
            while(st.top() != -1 && nums[st.top()] >= nums[i])
            {
                int idx = st.top();
                st.pop();
                int area = nums[idx] * (i - st.top() - 1);
                ans = max(ans, area);
            }
            st.push(i);
        }
        while(st.top() != -1)
        {
            int idx = st.top();
            st.pop();
            int area = nums[idx] * (n - st.top() - 1);
            ans = max(ans, area);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<int> dp(m);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '1')
                    dp[j]++;
                else
                    dp[j] = 0;
            }
            ans = max(ans, maxRectangle(dp));
        }
        return ans;
    }
};