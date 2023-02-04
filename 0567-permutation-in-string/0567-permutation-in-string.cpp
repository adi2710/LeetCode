class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26), freq2(26);
        for(char ch : s1)
            freq1[ch - 'a']++;
        for(int i = 0, j = 0; i + s1.size() <= s2.size(); i++)
        {
            while(j - i < s1.size())
                freq2[s2[j++] - 'a']++;
            if(freq1 == freq2)
                return true;
            freq2[s2[i] - 'a']--;
        }
        return false;
    }
};