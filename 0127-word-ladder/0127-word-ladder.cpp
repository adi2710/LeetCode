class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        words.erase(beginWord);
        queue<string> q;
        q.push(beginWord);
        int ans = 0;
        while(!q.empty())
        {
            ans++;
            for(int i = q.size(); i >= 1; i--)
            {
                string word = q.front();
                q.pop();
                if(word == endWord)
                    return ans;
                for(int idx = 0; idx < word.size(); idx++)
                {
                    char temp = word[idx];
                    for(char ch = 'a'; ch <= 'z'; ch++)
                    {
                        word[idx] = ch;
                        if(words.find(word) != words.end())
                        {
                            q.push(word);
                            words.erase(word);
                        }
                    }
                    word[idx] = temp;
                }
            }
        }
        return 0;
    }
};