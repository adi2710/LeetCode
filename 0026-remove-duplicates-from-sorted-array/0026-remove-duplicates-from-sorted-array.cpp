class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int x : nums)
        {
            if(nums[i] != x)
                nums[++i] = x;
        }
        return i + 1;
    }
};