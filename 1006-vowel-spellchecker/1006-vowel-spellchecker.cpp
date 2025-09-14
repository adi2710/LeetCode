class Solution {
    void maskVowels(string &word) {
        for(int j = 0; j < word.size(); j++) {
            if(word[j] == 'a' || 
                word[j] == 'e' ||
                word[j] == 'i' ||
                word[j] == 'o' ||
                word[j] == 'u') {
                    word[j] = '*';
            }
        }
    }

    string convertLowercase(string word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        return word;
    }
public:
    vector<string> spellchecker(vector<string>& wordList, vector<string>& queries) {
        unordered_map<string, int> exact, lowercase, vowelMasked;
        for(int i = 0; i < wordList.size(); i++) {
            if(exact.find(wordList[i]) == exact.end()) {
                exact[wordList[i]] = i;
            }
            string lowercaseWord = convertLowercase(wordList[i]);
            if(lowercase.find(lowercaseWord) == lowercase.end()) {
                lowercase[lowercaseWord] = i;
            }
            maskVowels(lowercaseWord);
            if(vowelMasked.find(lowercaseWord) == vowelMasked.end()) {
                vowelMasked[lowercaseWord] = i;
            }
        }

        vector<string> ans;
        ans.reserve(queries.size());

        for(string &query : queries) {
            if(exact.find(query) != exact.end()) {
                ans.push_back(wordList[exact[query]]);
                continue;
            }
            query = convertLowercase(query);
            if(lowercase.find(query) != lowercase.end()) {
                ans.push_back(wordList[lowercase[query]]);
                continue;
            }
            maskVowels(query);
            if(vowelMasked.find(query) != vowelMasked.end()) {
                ans.push_back(wordList[vowelMasked[query]]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};