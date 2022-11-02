class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        st.erase(start);
        queue<string> q;
        q.push(start);
        int ans = 0;
        vector<char> mutation = {'A', 'C', 'G', 'T'};
        while(!q.empty())
        {
            for(int i = q.size(); i >= 1; i--)
            {
                string cur = q.front();
                q.pop();
                if(cur == end)
                    return ans;
                for(int j = 0; j < cur.size(); j++)
                {
                    char ch = cur[j];
                    for(char c : mutation)
                    {
                        cur[j] = c;
                        if(st.find(cur) != st.end())
                        {
                            st.erase(cur);
                            q.push(cur);
                        }
                    }
                    cur[j] = ch;
                }
            }
            ans++;
        }
        return -1;
    }
};