class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for(int &query : queries)
        {
            int sum = 0, count = 0;
            for(int num : nums)
            {
                if(sum + num <= query)
                {
                    sum += num;
                    count++;
                }
            }
            query = count;
        }
        return queries;
    }
};