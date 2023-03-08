class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r = *max_element(piles.begin(), piles.end());
        while(r - l > 1)
        {
            int mid = l + (r - l) / 2;
            long long count = 0;
            for(int bananas : piles)
                count += ceil(1.0 * bananas / mid);
            if(count <= h)
                r = mid;
            else
                l = mid;
        }
        return r;
    }
};