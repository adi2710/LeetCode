class Solution {
public:
    int lengthOfLastWord(string s) {
        int pos = s.size() - 1;
        while(pos >= 0 && s[pos] == ' ')
            pos--;
        int start = pos;
        while(pos >= 0 && s[pos] != ' ') {
            pos--;
        }
        return start - pos;
    }
};