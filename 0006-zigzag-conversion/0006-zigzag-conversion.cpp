class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string ans;
        for(int row = 0; row < numRows; row++)
        {
            int mid = 2 * (numRows - row - 1);
            for(int i = row; i < s.size(); i += 2 * (numRows - 1))
            {
                ans += s[i];
                if(row >= 1 && row + 1 < numRows && i + mid < s.size())
                    ans += s[i + mid];
            }
        }
        return ans;
    }
};