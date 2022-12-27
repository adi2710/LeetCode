class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for(int i = 0; i < capacity.size(); i++)
            capacity[i] -= rocks[i];
        sort(capacity.begin(), capacity.end());
        int ans = 0;
        for(int cap : capacity)
        {
            if(additionalRocks - cap >= 0)
            {
                additionalRocks -= cap;
                ans++;
            }
            else
                break;
        }
        return ans;
    }
};