class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp, palin;
        bool isOdd = false;
        int ans = 0;
        for(string &word : words)
        {
            if(word[0] == word[1]){
                palin[word]++;
                continue;
            }
            if(mp.find(word) != mp.end()){
                mp[word]--;
                if(mp[word] == 0)
                    mp.erase(word);
                ans += 4;
            }
            else{
                string rev = word;
                swap(rev[0], rev[1]);
                mp[rev]++;
            }
        }
        for(auto &[word, cnt] : palin)
        {
            if(cnt & 1){
                isOdd = true;
                ans += (cnt - 1) * 2;
            }
            else
                ans += cnt * 2;
        }
        if(isOdd)
            ans += 2;
        return ans;
    }
};