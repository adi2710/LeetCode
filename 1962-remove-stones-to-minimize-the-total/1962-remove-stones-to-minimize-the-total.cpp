class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int stones : piles)
            pq.push(stones);
        while(k--)
        {
            int stones = pq.top();
            pq.pop();
            pq.push(stones - stones / 2);
        }
        int ans = 0;
        while(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};