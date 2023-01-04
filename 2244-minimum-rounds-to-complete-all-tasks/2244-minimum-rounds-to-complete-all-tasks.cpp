class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        for(int task : tasks)
            freq[task]++;
        int ans = 0;
        for(auto [task, count] : freq)
        {
            if(count <= 1)
                return -1;
            int pos = count / 2, rem = 0;
            if(count & 1)
                rem = (pos - 1) % 3;
            else
                rem = pos % 3;
            count -= rem * 2;
            ans += rem + count / 3;
        }
        return ans;
    }
};