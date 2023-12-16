class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        int fact = 1;
        for(int i = 1; i < n; i++)
            fact *= i;
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        string ans;
        while(!nums.empty()) {
            int pos = k / fact;
            ans.push_back(nums[pos] + '0');
            nums.erase(nums.begin() + pos);
            k %= fact;
            fact /= max(1, (int)nums.size());
        }
        return ans;
    }
};