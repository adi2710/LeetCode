class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq1(26), freq2(26);
        for(char ch : s)
            freq1[ch - 'a']++;
        for(char ch : t)
            freq2[ch - 'a']++;
        return freq1 == freq2;
    }
};