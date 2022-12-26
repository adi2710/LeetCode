class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0;
        for(int i = 0; i < nums.size() && pos + 1 < nums.size(); i++)
        {
            if(pos >= i)
                pos = max(pos, i + nums[i]);
        }
        return pos >= nums.size() - 1;
    }
};