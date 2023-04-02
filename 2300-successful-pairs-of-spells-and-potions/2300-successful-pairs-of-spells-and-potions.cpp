class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for(int spell : spells)
        {
            long long potion = ceil(1.0 * success / spell);
            int cnt = potions.end() - lower_bound(potions.begin(), potions.end(), potion);
            ans.push_back(cnt);
        }
        return ans;
    }
};