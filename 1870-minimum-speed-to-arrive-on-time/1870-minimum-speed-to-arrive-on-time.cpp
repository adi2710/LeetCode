class Solution {
public:
    
    double countTime(vector<int>& dist, int speed)
    {
        double time = 1.0 * dist.back() / speed;
        for(int i = 0; i < dist.size() - 1; i++)
            time += ceil(1.0 * dist[i] / speed);
        return time;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(dist.size() - 1 >= hour)
            return -1;
        int l = 0, r = 1e7;
        while(r - l > 1)
        {
            int mid = l + (r - l) / 2;
            if(countTime(dist, mid) - hour <= 1e-10)
                r = mid;
            else
                l = mid;
        }
        return r;
    }
};