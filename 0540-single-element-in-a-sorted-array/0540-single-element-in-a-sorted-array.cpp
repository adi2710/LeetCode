class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n - 1;
        while(l <= r)
        {
            int mid = l + (r - l) / 2, last = -1;
            if(mid + 1 < n && nums[mid] == nums[mid + 1])
                last = mid + 1;
            else if(mid - 1 >= 0 && nums[mid] == nums[mid - 1])
                last = mid;
            if(last == -1)
                return nums[mid];
            else if(last & 1 ^ 1)
                r = last - 2;
            else
                l = last + 1;
        }
        return -1;
    }
};