class Solution {
public:
    
    bool match(string &text, string &pattern)
    {
        for(int i = 0; i < text.size(); i++)
        {
            if(text[i] != pattern[i % pattern.size()])
                return false;
        }
        return true;
    }
    
    string gcdOfStrings(string str1, string str2) {
        int hcf = __gcd(str1.size(), str2.size());
        string pattern = str2.substr(0, hcf);
        if(match(str1, pattern) && match(str2, pattern))
            return pattern;
        return "";
    }
};