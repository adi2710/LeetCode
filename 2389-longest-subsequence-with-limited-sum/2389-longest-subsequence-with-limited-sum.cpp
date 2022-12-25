class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int pre = 0;
        for(int &num : nums){
            pre += num;
            num = pre;
        }
        for(int &query : queries)
            query = upper_bound(nums.begin(), nums.end(), query) - nums.begin();
        return queries;
    }
};