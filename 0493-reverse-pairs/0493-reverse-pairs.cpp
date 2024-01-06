class Solution {
public:
    int merge(int l, int m, int r, vector<int> &nums, vector<int> &tmp) {
        int i = l, j = m + 1, k = 0, count = 0;
        for(i = l; i <= m; i++){
            while(j <= r && nums[i] > 2ll * nums[j]) j++;
            count += j - m - 1;
        }
        i = l, j = m + 1;
        while(i <= m && j <= r) {
            if(nums[i] <= nums[j])
                tmp[k++] = nums[i++];
            else
                tmp[k++] = nums[j++];
        }
        while(i <= m)
            tmp[k++] = nums[i++];
        while(j <= r)
            tmp[k++] = nums[j++];
        for(i = 0; i < k; i++)
            nums[i + l] = tmp[i];
        return count;
    }
    
    int mergeSort(int l, int r, vector<int> &nums, vector<int> &tmp) {
        if(l >= r)
            return 0;
        int mid = l + (r - l) / 2;
        int lf = mergeSort(l, mid, nums, tmp);
        int rt = mergeSort(mid + 1, r, nums, tmp);
        return lf + rt + merge(l, mid, r, nums, tmp);
    }
    
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return mergeSort(0, nums.size() - 1, nums, tmp);
    }
};