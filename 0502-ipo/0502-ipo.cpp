class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> ar(n);
        for(int i = 0; i < n; i++)
            ar[i] = {capital[i], profits[i]};
        sort(ar.begin(), ar.end());
        priority_queue<int> pq;
        for(int i = 0, j = 0; i < k; i++)
        {
            while(j < n && w >= ar[j].first)
                pq.push(ar[j++].second);
            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }
};