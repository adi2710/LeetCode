class Solution {
public:
    
    void solve(int i, vector<int> &count, int &ans, string &tiles, vector<int> &fact) {
        if(i == tiles.size()) {
            int sum = fact[accumulate(count.begin(), count.end(), 0)];
            for(int x : count)
                sum /= fact[x];
            ans += sum;
            return;
        }
        
        count[tiles[i] - 'A']++;
        solve(i + 1, count, ans, tiles, fact);
        count[tiles[i] - 'A']--;
        
        while(i + 1 < tiles.size() && tiles[i] == tiles[i + 1]) i++;
        solve(i + 1, count, ans, tiles, fact);
    }
    
    int numTilePossibilities(string tiles) {
        int ans = 0;
        vector<int> fact(8), count(26);
        fact[0] = 1;
        for(int i = 1; i < 8; i++)
            fact[i] = fact[i - 1] * i;
        sort(tiles.begin(), tiles.end());
        solve(0, count, ans, tiles, fact);
        return ans - 1;
    }
};