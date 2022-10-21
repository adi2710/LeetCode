class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int n = points.size(), ans = 0, cnt = 0;
        vector<double> point;
        for(auto &pt : points)
        {
            int x1 = location[0], y1 = location[1], x2 = pt[0], y2 = pt[1];
            if(x1 == x2 && y1 == y2)
                cnt++;
            else{
                double ang = atan2(y2 - y1, x2 - x1);
                ang *= 180 / 3.1415926535897932384626433;
                point.push_back(ang);
            }
        }   
        sort(point.begin(), point.end());
        n = point.size();
        for(int i = 0; i < n; i++) 
            point.push_back(point[i] + 360);
        n = point.size();
        for(int l = 0, r = 0; l < point.size(); l++)
        {
            while(r < n && point[r] - point[l] <= angle)
                r++;
            ans = max(ans, point[r - 1] - point[l] > angle ? r - l - 1 : r - l);  
        }
        return ans + cnt;
    }
};