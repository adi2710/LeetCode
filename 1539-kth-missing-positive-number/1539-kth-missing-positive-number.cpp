class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int prev = 0;
        for(int x : arr)
        {
            if(x - prev - 1 >= k)
                return prev + k;
            k -= x - prev - 1;
            prev = x;
        }
        return prev + k;
    }
};