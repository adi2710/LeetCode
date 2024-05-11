class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers(n);
        for(int i = 0; i < n; i++)
            workers[i] = {(double) wage[i] / quality[i], quality[i]};
        sort(workers.begin(), workers.end());
        
        int sum = 0; double ans = 1e9;
        priority_queue<int> pq;
        for(int i = 0; i < n; i++)
        {
            pq.push(workers[i].second);
            sum += workers[i].second;
            if(pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            if(i >= k - 1)
                ans = min(ans, sum * workers[i].first);
        }
        return ans;
    }
};