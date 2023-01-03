class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        unordered_set<int> st;
        for(int i = 1; i < strs.size(); i++)
        {
            for(int j = 0; j < strs[i].size(); j++)
            {
                if(st.find(j) != st.end())
                    continue;
                if(strs[i - 1][j] > strs[i][j])
                    st.insert(j);
            }
        }
        return st.size();
    }
};