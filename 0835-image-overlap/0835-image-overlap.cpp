class Solution {
public:
    vector<int> nonZeroCells(vector<vector<int>> &img)
    {
        vector<int> vec;
        for(int i = 0; i < img.size(); i++)
        {
            for(int j = 0; j < img[0].size(); j++)
            {
                if(img[i][j] == 1)
                    vec.push_back(i * 100 + j);
            }
        }
        return vec;
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<int> ar = nonZeroCells(img1);
        vector<int> br = nonZeroCells(img2);
        int ans = 0;
        unordered_map<int, int> groupCnt;
        for(int a : ar)
        {
            for(int b : br)
            {
                int dis = a - b;
                groupCnt[dis]++;
                ans = max(ans, groupCnt[dis]);
            }
        }
        return ans;
    }
};