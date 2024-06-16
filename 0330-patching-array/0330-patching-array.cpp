class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        long long mx = 0;
        for(int x : nums) {
            while(x > mx + 1) {
                mx += mx + 1;
                ans++;
                if(mx > n)
                    return ans;
            }
            mx += x;
            if(mx > n)
                return ans;
        }
        while(n > mx) {
            mx += mx + 1;
            ans++;
        }
        return ans;
    }
};