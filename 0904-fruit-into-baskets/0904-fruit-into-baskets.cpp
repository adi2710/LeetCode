class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int ans = 0;
        for(int i = 0, j = 0; i < fruits.size(); i++)
        {
            while(j < fruits.size() && freq.size() <= 2)
                freq[fruits[j++]]++;
            ans = max(ans, (freq.size() > 2 ? j - i - 1 : j - i));
            freq[fruits[i]]--;
            if(freq[fruits[i]] == 0)
                freq.erase(fruits[i]);
        }
        return ans;
    }
};