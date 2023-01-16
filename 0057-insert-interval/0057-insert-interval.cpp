class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if(!intervals.empty() && intervals[0][0] < newInterval[0])
            ans.push_back(intervals[0]);
        else{
            ans.push_back(newInterval);
            newInterval.clear();
        }
        for(auto &interval : intervals)
        {
            if(!newInterval.empty())
            {
                if(ans.back()[1] >= newInterval[0]){
                    ans.back()[1] = max(ans.back()[1], newInterval[1]);
                    newInterval.clear();
                }
                else if(newInterval[0] < interval[0])
                {
                    ans.push_back(newInterval);
                    newInterval.clear();
                }
            }
            if(ans.back()[1] >= interval[0])
                ans.back()[1] = max(ans.back()[1], interval[1]);
            else
                ans.push_back(interval);
        }
        if(!newInterval.empty())
        {
            if(ans.back()[1] >= newInterval[0])
                ans.back()[1] = max(ans.back()[1], newInterval[1]);
            else
                ans.push_back(newInterval);
        }
        return ans;
    }
};