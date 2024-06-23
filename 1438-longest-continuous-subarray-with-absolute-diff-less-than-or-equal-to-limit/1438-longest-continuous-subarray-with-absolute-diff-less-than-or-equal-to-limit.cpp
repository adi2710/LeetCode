class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> mn, mx;
        int i = 0, j;
        for(j = 0; j < nums.size(); j++)
        {
            while(!mn.empty() && mn.back() > nums[j])
                mn.pop_back();
            while(!mx.empty() && mx.back() < nums[j])
                mx.pop_back();
            mn.push_back(nums[j]);
            mx.push_back(nums[j]);
            if(mx.front() - mn.front() > limit)
            {
                if(mn.front() == nums[i])
                    mn.pop_front();
                if(mx.front() == nums[i])
                    mx.pop_front();
                i++;
            }
        }
        return j - i;
    }
};