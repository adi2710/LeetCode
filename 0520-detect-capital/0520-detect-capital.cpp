class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for(char ch : word)
            cnt += 'A' <= ch && ch <= 'Z';
        if(cnt == 0 || cnt == word.size())
            return true;
        if(cnt == 1 && 'A' <= word[0] && word[0] <= 'Z')
            return true;
        return false;
    }
};
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);