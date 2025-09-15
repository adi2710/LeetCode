class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        bool word = true;
        int ans = 1;
        for(char ch : text) {
            if(ch == ' ') {
                ans++;
                word = true;
            } else if(!word) {
                continue;
            } else if(broken.find(ch) != broken.end()) {
                ans--;
                word = false;
            }
        }
        return ans;
    }
};