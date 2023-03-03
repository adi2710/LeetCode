class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.size();
        vector<int> lps(m);
        for(int i = 1, j = 0; i < m;)
        {
            if(needle[i] == needle[j]){
                lps[i] = j + 1;
                i++;
                j++;
            }
            else
            {
                if(j != 0)
                    j = lps[j - 1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        for(int i = 0, j = 0; i < haystack.size();)
        {
            if(needle[j] == haystack[i])
            {
                j++;
                i++;
            }
            else
            {
                if(j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
            if(j == m)
                return i - j;
        }
        return -1;
    }
};