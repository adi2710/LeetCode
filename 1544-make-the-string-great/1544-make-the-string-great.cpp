class Solution {
public:
    
    bool checkSame(char ch1, char ch2)
    {
        if(ch1 == ch2)
            return false;
        if(ch1 < ch2)
            swap(ch1, ch2);
        ch1 -= 32;
        return ch1 == ch2;
    }
    
    string makeGood(string s) {
        int i = 0;
        for(int j = 1; j < s.size(); j++)
        {
            if(i < 0 || !checkSame(s[i], s[j]))
                s[++i] = s[j];
            else
                i--;
        }
        return s.substr(0, i + 1);
    }
};