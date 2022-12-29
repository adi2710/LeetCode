class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i = 0; i < tasks.size(); i++)
            tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int i = 0;
        long curTime = 1;
        vector<int> ans;
        while(i < tasks.size() || !pq.empty())
        {
            while(i < tasks.size() && curTime >= tasks[i][0])
                pq.push({tasks[i][1], tasks[i][2]}), i++;
            if(pq.empty())
            {
                curTime = i < tasks.size() ? tasks[i][0] : curTime;
                continue;
            }
            ans.push_back(pq.top().second);
            curTime += pq.top().first;
            pq.pop();
        }
        return ans;
    }
};