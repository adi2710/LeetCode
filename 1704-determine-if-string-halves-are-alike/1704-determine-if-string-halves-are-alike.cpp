class Solution {
public:
    
    bool isVowel(char ch)
    {
        if(ch < 'a')
            ch += 32;
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    bool halvesAreAlike(string s) {
        int cnt1 = 0, cnt2 = 0;
        for(int l = 0, r = s.size() - 1; l < r; l++, r--)
        {
            cnt1 += isVowel(s[l]);
            cnt2 += isVowel(s[r]);
        }
        return cnt1 == cnt2;
    }
};