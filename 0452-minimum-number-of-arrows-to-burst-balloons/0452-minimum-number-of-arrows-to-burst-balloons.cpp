class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int maxLimit = points[0][1], ans = 1; 
        for(auto &point : points)
        {
            if(point[0] > maxLimit)
                ans++, maxLimit = point[1];
            else
                maxLimit = min(maxLimit, point[1]);
        }
        return ans;
    }
};