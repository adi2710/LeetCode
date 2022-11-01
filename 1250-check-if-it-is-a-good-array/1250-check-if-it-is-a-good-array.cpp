class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int hcf = 0;
        for(int x : nums)
			hcf = __gcd(hcf, x);
		return hcf == 1;
    }
};