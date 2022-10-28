class Solution {
public:
    
    struct compare{
        size_t operator()(const pair<int, int> &a) const
        {
            auto hash1 = hash<int>{}(a.first);
            auto hash2 = hash<int>{}(a.second);
            
            if(hash1 != hash2)
                return hash1 ^ hash2;
            return hash1;
        }
    };
    
    vector<pair<int, int>> nonZeroCells(vector<vector<int>> &img)
    {
        vector<pair<int, int>> vec;
        for(int i = 0; i < img.size(); i++)
        {
            for(int j = 0; j < img[0].size(); j++)
            {
                if(img[i][j] == 1)
                    vec.push_back({i, j});
            }
        }
        return vec;
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> ar = nonZeroCells(img1);
        vector<pair<int, int>> br = nonZeroCells(img2);
        int ans = 0;
        unordered_map<pair<int, int>, int, compare> groupCnt;
        for(auto a : ar)
        {
            for(auto b : br)
            {
                pair<int, int> dis = {a.first - b.first, a.second - b.second};
                groupCnt[dis]++;
                ans = max(ans, groupCnt[dis]);
            }
        }
        return ans;
    }
};