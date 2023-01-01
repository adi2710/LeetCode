class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> mp1(26);
        unordered_map<string, char> mp2;
        stringstream ss(s);
        string word;
        int i = 0;
        while(ss >> word)
        {
            if(i >= pattern.size())
                return false;
            if(mp1[pattern[i] - 'a'] == "")
                mp1[pattern[i] - 'a'] = word;
            if(mp2.find(word) == mp2.end())
                mp2[word] = pattern[i];
            if(mp1[pattern[i] - 'a'] != word)
                return false;
            if(mp2[word] != pattern[i])
                return false;
            i++;
        }
        return i == pattern.size();
    }
};