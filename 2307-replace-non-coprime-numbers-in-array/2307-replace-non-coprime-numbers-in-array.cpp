class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            while(!ans.empty()) {
                int hcf = __gcd(ans.back(), num);
                if(hcf == 1) {
                    break;
                }
                num = 1ll * num * ans.back() / hcf;
                ans.pop_back();
            }
            ans.push_back(num);
        }
        return ans;
    }
};