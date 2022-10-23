class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum = 0;
        for(int i = 1; i <= nums.size(); i++)
            sum ^= i ^ nums[i - 1];
        int lsb = sum & -sum, a = 0, b = 0;
        for(int i = 1; i <= nums.size(); i++)
        {
            if(lsb & i)
                a ^= i;
            else
                b ^= i;
            if(lsb & nums[i - 1])
                a ^= nums[i - 1];
            else
                b ^= nums[i - 1];
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == b)
            {
                swap(a, b);
                break;
            }
        }
        return {a, b};
    }
};