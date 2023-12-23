class Solution {
public:
    inline string hash(int a, int b) {
        return to_string(a) + "," + to_string(b);
    }
    bool isPathCrossing(string path) {
        unordered_set<string> st;
        int x = 0, y = 0;
        st.insert(hash(x, y));
        for(char ch : path) {
            if(ch == 'N')
                y++;
            else if(ch == 'S')
                y--;
            else if(ch == 'E')
                x++;
            else
                x--;
            string h = hash(x, y);
            if(st.find(h) != st.end())
                return true;
            st.insert(h);
        }
        return false;
    }
};