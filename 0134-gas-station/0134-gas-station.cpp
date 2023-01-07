class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, rem = 0, ans = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            sum += gas[i] - cost[i];
            if(sum < 0)
            {
                rem += sum;
                sum = 0;
                ans = i + 1;
            }
        }
        if(sum + rem < 0)
            ans = -1;
        return ans;
    }
};