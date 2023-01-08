class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 1;
        unordered_map<double, int> mp;
        
        for(int i = 0; i < n; i++)
        {
            mp.clear();
            for(int j = i + 1; j < n; j++)
            {
                double slope = 1e9;
                if(points[j][0] != points[i][0])
                    slope = (1.0 * points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                mp[slope]++;
                ans = max(ans, mp[slope] + 1);
            }
        }
        return ans;
    }
};