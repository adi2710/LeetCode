class Solution {
public:
    
    vector<int> findMax(vector<vector<int>> &points, int skip) {
        int mxSum = INT_MIN, mnSum = INT_MAX, mxDiff = INT_MIN, mnDiff = INT_MAX;
        int mxSum_p = -1, mnSum_p = -1, mxDiff_p = -1, mnDiff_p = -1;
        for(int i = 0; i < points.size(); i++) {
            if(i == skip)
                continue;
            int sum =  points[i][0] + points[i][1];
            int diff = points[i][0] - points[i][1];
            if(mnSum > sum) {
                mnSum = sum;
                mnSum_p = i;
            }
            if(mxSum < sum) {
                mxSum = sum;
                mxSum_p = i;
            }
            if(mnDiff > diff) {
                mnDiff = diff;
                mnDiff_p = i;
            }
            if(mxDiff < diff) {
                mxDiff = diff;
                mxDiff_p = i;
            }
        }
        vector<int> ans;
        if(mxSum - mnSum > mxDiff - mnDiff)
            ans = {mxSum - mnSum, mnSum_p, mxSum_p};
        else
            ans = {mxDiff - mnDiff, mnDiff_p, mxDiff_p};
        return ans;
    }
    
    int minimumDistance(vector<vector<int>>& points) {
        vector<int> p = findMax(points, -1);
        return min(findMax(points, p[1])[0], findMax(points, p[2])[0]);
    }
};