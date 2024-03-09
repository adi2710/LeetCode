class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(i + 1 >= k) {
                ans = max(ans, (double)sum / k);
                sum -= nums[i - k + 1];
            }
        }
        return ans;
    }
};