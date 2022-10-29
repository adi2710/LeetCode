class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> v;
        int n = plantTime.size(), bloomTime = 0, mxPlantTime = 0;
        for(int i = 0; i < n; i++)
            v.push_back({plantTime[i], growTime[i]});
        sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            if(a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        });
        for(int i = 0; i < n; i++)
        {
            mxPlantTime = mxPlantTime + v[i].first;
            bloomTime = max(bloomTime, mxPlantTime + v[i].second);
        }
        return bloomTime;
    }
};
