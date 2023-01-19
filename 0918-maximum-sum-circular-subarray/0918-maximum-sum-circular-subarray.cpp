class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_ans = INT_MIN, min_ans = INT_MAX, sum = 0, max_sum = 0, min_sum = 0;
        for(int num : nums)
        {
            max_sum = max(max_sum, 0) + num;
            max_ans = max(max_ans, max_sum);
            min_sum = min(min_sum, 0) + num;
            min_ans = min(min_ans, min_sum);
            sum += num;
        }
        if(min_ans == sum)
            return max_ans;
        return max(max_ans, sum - min_ans);
    }
};