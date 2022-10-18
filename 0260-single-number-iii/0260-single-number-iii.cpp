class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        for(int x : nums)
            sum ^= x;
        int lsb = sum & -(long)sum, sum1 = 0, sum2 = 0;
        for(int x : nums)
        {
            if(x & lsb)
                sum1 ^= x;
            else
                sum2 ^= x;
        }
        return {sum1, sum2};
    }
};