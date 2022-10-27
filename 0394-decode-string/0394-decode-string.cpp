class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ']')
                st.push(string(1, s[i]));
            else
            {
                string rev;
                while(st.top() != "[")
                    rev += st.top(), st.pop();
                st.pop();
                
                
                string n;
                while(!st.empty() && isdigit(st.top()[0]))
                    n += st.top(), st.pop();
                reverse(n.begin(), n.end());
                int num = stoi(n);
                while(num--)
                    st.push(rev);
            }
        }
        string ans;
        while(!st.empty())
            ans += st.top(), st.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};