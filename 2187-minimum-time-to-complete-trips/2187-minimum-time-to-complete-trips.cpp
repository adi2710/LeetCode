class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 0, r = 1ll * *min_element(time.begin(), time.end()) * totalTrips;
        while(r - l > 1)
        {
            long long mid = l + (r - l) / 2;
            long long count = 0;
            for(int t : time)
                count += mid / t;
            if(count >= totalTrips)
                r = mid;
            else
                l = mid;
        }
        return r;
    }
};