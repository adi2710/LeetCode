class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](const int &a, const int &b){
            return efficiency[a] > efficiency[b];
        });
        long ans = 0, sum = 0;
        for(int i = 0; i < n; i++)
        {
            pq.push(speed[idx[i]]);
            sum += speed[idx[i]];
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sum * efficiency[idx[i]]);
        }
        return ans % (int)(1e9 + 7);
    }
};