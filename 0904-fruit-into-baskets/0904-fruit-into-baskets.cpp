class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int n = fruits.size(), ans = 0;
        for(int l = 0, r = 0; l < n; l++)
        {
            while(r < n && freq.size() <= 2)
                freq[fruits[r++]]++;
            
            ans = max(ans, freq.size() > 2 ? r - l - 1 : r - l);
            freq[fruits[l]]--;
            if(freq[fruits[l]] == 0)
                freq.erase(fruits[l]);
        }
        return ans;
    }
};