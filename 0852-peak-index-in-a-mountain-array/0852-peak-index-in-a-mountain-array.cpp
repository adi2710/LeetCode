class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = -1, r = arr.size() - 1;
        while(r - l > 1)
        {
            int mid = l + (r - l) / 2;
            if(mid + 1 < arr.size() && arr[mid] > arr[mid + 1])
                r = mid;
            else
                l = mid;
        }
        return r;
    }
};