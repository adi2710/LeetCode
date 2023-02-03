class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq1(26), freq2(26);
        for(char ch : p)
            freq1[ch - 'a']++;
        vector<int> ans;
        for(int i = 0, j = 0; i + p.size() - 1 < s.size(); i++)
        {
            while(j - i < p.size())
                freq2[s[j++] - 'a']++;
            if(freq1 == freq2)
                ans.push_back(i);
            freq2[s[i] - 'a']--;
        }
        return ans;
    }
};