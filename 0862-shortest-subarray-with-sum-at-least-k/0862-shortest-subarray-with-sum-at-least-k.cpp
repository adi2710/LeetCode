class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long, int>> dq;
        long sum = 0;
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(sum >= k)
                ans = min(ans, i + 1);
            int last = -1;
            while(!dq.empty() && sum - dq.front().first >= k)
                last = dq.front().second, dq.pop_front();
            if(last != -1)
                ans = min(ans, i - last);
            while(!dq.empty() && dq.back().first >= sum)
                dq.pop_back();
            dq.push_back({sum, i});
        }
        return ans == INT_MAX ? -1 : ans;
    }
};