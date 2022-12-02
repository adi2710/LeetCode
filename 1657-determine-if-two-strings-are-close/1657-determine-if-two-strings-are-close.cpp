class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;
        vector<int> freq1(26), freq2(26);
        for(char ch : word1)
            freq1[ch - 'a']++;
        for(char ch : word2){
            freq2[ch - 'a']++;
            if(freq1[ch - 'a'] == 0)
                return false;
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        return freq1 == freq2;
    }
};