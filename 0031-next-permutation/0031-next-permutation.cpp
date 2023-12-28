class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i + 1]) i--;
        if(i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int pos = nums.size() - 1;
        while(pos > i && nums[pos] <= nums[i]) pos--;
        swap(nums[i], nums[pos]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};