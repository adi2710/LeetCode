class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, pair<int, int>> mp;//num -> {sum of indices, cnt}
        mp[0] = {-1, 1};
        int sum = 0, ans = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            sum ^= arr[i];
            if(mp.find(sum) != mp.end())
            {
                int prevSum = mp[sum].first, cnt = mp[sum].second;
                ans += (i - 1) * cnt - prevSum;
            }
            mp[sum].first += i;
            mp[sum].second++;
        }
        return ans;
    }
};