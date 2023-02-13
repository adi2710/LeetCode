class Solution {
public:
    int countOdds(int low, int high) {
        int cnt = 0;
        if(high & 1)
        {
            cnt += high > low;
            high--;
        }
        cnt += (high - low) / 2 + (low & 1);
        return cnt;
    }
};