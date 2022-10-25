class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
        while(r1 < word1.size() && r2 < word2.size())
        {
            if(word1[r1][c1] != word2[r2][c2])
                return false;
            c1++, c2++;
            if(c1 == word1[r1].size())
                r1++, c1 = 0;
            if(c2 == word2[r2].size())
                r2++, c2 = 0;
        }
        return r1 == word1.size() && r2 == word2.size();
    }
};