class Solution {
public:
    
    int solve(int i, vector<int> &nums)
    {
        if(i == nums.size())
            return 0;
        
        set<int> st;
        int cnt = 0, no = 0;
        for(int j = i; j < nums.size(); j++)
        {
            if(st.find(nums[j]) != st.end()){
                cnt += no;
                continue;
            }
            if(st.empty())
            {
                st.insert(nums[j]);
                continue;
            }
            auto next = st.upper_bound(nums[j]);
            if(next == st.end())
            {
                auto prev = std::next(next, -1);
                if(nums[j] - *prev > 1)
                    no++;
            }
            else
            {
                if(next != st.begin())
                {
                    auto prev = std::next(next, -1);
                    if(nums[j] - *prev > 1 || *next - nums[j] > 1)
                        no++;
                    if(nums[j] - *prev == 1 || *next - nums[j] == 1)
                        no--;
                }
                else if(*next - nums[j] > 1)
                    no++;
            }
            cnt += no;
            st.insert(nums[j]);
        }
        int sum = cnt + solve(i + 1, nums);
        // cout << i << ' ' << cnt << ' ' << sum << endl;
        return sum;
    }
    
    int sumImbalanceNumbers(vector<int>& nums) {
        return solve(0, nums);
    }
};