class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for(char ch : s)
        {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                vowels.push_back(ch);
        }
        sort(vowels.begin(), vowels.end());
        int pos = 0;
        for(int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                s[i] = vowels[pos++];
        }
        return s;
    }
};