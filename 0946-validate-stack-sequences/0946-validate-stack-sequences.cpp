class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i, j;
        for(i = 0, j = 0; i < pushed.size() && j < popped.size();)
        {
            if(st.empty() || st.top() != popped[j])
                st.push(pushed[i++]);
            else if(st.top() == popped[j])
                st.pop(), j++;
        }
        while(j < popped.size() && !st.empty() && st.top() == popped[j])
            st.pop(), j++;
        return st.empty();
    }
};