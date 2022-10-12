class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
                return mid;
            
            bool isGreaterKey = nums[0] <= target;
            bool isGreaterPart = nums[0] <= nums[mid];
            if(nums[mid] < target)
            {
                if(isGreaterKey == isGreaterPart)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else
            {
                if(isGreaterKey == isGreaterPart)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};