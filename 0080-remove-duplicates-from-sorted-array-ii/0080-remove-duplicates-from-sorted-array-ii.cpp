class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 1; j < nums.size(); j++)
        {
            int x = nums[j];
            if(nums[i] != x)
                nums[++i] = x;
            else if(i == 0 || nums[i - 1] != nums[i])
                nums[++i] = x;
        }
        return i + 1;
    }
};