class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> loss;
        for(auto match : matches){
            loss[match[1]]++;
            loss[match[0]] = max(loss[match[0]], 0);
        }
        vector<vector<int>> ans(2);
        for(auto [num, freq] : loss)
        {
            if(freq <= 1)
                ans[freq].push_back(num);
        }
        return ans;
    }
};