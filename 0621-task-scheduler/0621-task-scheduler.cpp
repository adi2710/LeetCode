class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        for(char ch : tasks)
            freq[ch - 'A']++;
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        for(int &x : freq)
        {
            if(x > 0)
                pq.push(x);
        }
        int timer = 0;
        while(!pq.empty() || !q.empty())
        {
            while(!q.empty() && q.front().first == timer)
            {
                pq.push(q.front().second);
                q.pop();
            }
            if(!pq.empty())
            {
                int cnt = pq.top() - 1;
                pq.pop();
                if(cnt > 0)
                    q.push({timer + n + 1, cnt});
            }
            timer++;
        }
        return timer;
    }
};