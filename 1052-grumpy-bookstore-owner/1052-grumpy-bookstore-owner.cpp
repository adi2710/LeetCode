class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int noGrumpy = 0, n = customers.size(), l = 0, r = 0;
        for(int i = 0; i < n; i++)
        {
            if(!grumpy[i])
                noGrumpy += customers[i];
        }
        int ans = 0, grumpySum = 0;
        while(r < n)
        {
            while(r - l < minutes)
            {
                if(grumpy[r])
                    grumpySum += customers[r];
                r++;
            }
            ans = max(ans, grumpySum + noGrumpy);
            grumpySum -= grumpy[l] == 1 ? customers[l] : 0;
            l++;
        }
        return ans;
    }
};