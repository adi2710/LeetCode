class Solution {
public:
    const char BASE = 'A';
    int lhsChars[26], rhsChars[26];
    vector<int> chars;
    unordered_set<int> firstChars;
    
    bool check(int i, int bitmask, int lhs, int rhs) {
        if(i == chars.size()) {
            return lhs == rhs;
        }
        for(int j = 0; j <= 9; j++) {
            if(j == 0 && firstChars.find(chars[i]) != firstChars.end())
                continue;
            if(!(bitmask & (1 << j))) {
                bitmask |= (1 << j);
                if(check(i + 1, bitmask, lhs + lhsChars[chars[i]] * j, rhs + rhsChars[chars[i]] * j))
                    return true;
                bitmask &= ~(1 << j);
            }
        }
        return false;
    }
        
    bool isSolvable(vector<string>& words, string result) {
        vector<int> power = {0, 1, 10, 100, 1000, 10000, 100000, 1000000};
        for(string &word : words) {
            if(word.size() > 1)
                firstChars.insert(word.front() - BASE);
            for(int i = 0; i < word.size(); i++)
                lhsChars[word[i] - BASE] += power[word.size() - i];
        }
        if(result.size() > 1)
            firstChars.insert(result.front() - BASE);
        for(int i = 0; i < result.size(); i++)
            rhsChars[result[i] - BASE] += power[result.size() - i];
        for(int i = 0; i < 26; i++) {
            if(lhsChars[i] + rhsChars[i] > 0)
                chars.push_back(i);
        }
        return check(0, 0, 0, 0);
    }
};