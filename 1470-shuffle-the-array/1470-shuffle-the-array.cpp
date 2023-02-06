class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i = 0; i < n; i++)
            nums[i] += nums[i + n] * 1001;
        for(int i = n - 1; i >= 0; i--)
        {
            nums[i * 2 + 1] = nums[i] / 1001;
            nums[i * 2] = nums[i] % 1001;
        }
        return nums;
    }
};