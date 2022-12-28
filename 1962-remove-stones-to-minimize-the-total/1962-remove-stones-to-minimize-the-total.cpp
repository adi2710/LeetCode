class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        int ans = accumulate(piles.begin(), piles.end(), 0);
        while(k--)
        {
            int stones = pq.top();
            pq.pop();
            ans -= stones / 2;
            pq.push(stones - stones / 2);
        }
        return ans;
    }
};