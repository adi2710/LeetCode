class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            while(!ans.empty()) {
                int last = ans.back();
                int hcf = __gcd(last, num);
                if(hcf == 1) {
                    break;
                }
                ans.pop_back();
                num = 1ll * num * last / hcf;
            }
            ans.push_back(num);
        }
        return ans;
    }
};