class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        s += " ";
        int l1 = 0;
        for(int l2 = 0, r = 0; r < s.size(); r++)
        {
            if(s[r] != ' ')
                s[l2++] = s[r];
            else if(l1 < l2)
            {
                for(int lf = l1, rt = l2 - 1; lf < rt; lf++, rt--)
                    swap(s[lf], s[rt]);
                s[l2++] = ' ';
                l1 = l2;
            }
        }
        return s.substr(0, l1 - 1);
    }
};