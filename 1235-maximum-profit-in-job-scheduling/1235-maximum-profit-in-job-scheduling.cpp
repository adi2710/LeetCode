class Solution {
public:
    
    int dp[50000];
    int lower_bound(vector<tuple<int, int, int>> &jobs, int time)
    {
        auto [startTime, endTime, profit] = jobs.back();
        if(startTime < time)
            return jobs.size();
        int l = -1, r = jobs.size() - 1;
        while(r - l > 1)
        {
            int mid = l + (r - l) / 2;
            auto [startTime, endTime, profit] = jobs[mid];
            if(startTime >= time)
                r = mid;
            else
                l = mid;
        }
        return r;
    }
    
    int solve(int i, vector<tuple<int, int, int>> &jobs)
    {
        if(i >= jobs.size())
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        auto [startTime, endTime, profit] = jobs[i];
        int nxt = lower_bound(jobs, endTime);
        return dp[i] = max(profit + solve(nxt, jobs), solve(i + 1, jobs));
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        vector<tuple<int, int, int>> jobs(profit.size());
        for(int i = 0; i < profit.size(); i++)
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        sort(jobs.begin(), jobs.end());
        return solve(0, jobs);
    }
};