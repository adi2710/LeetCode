class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        auto compare = [](const pair<int, int>& a, const pair<int, int>& b){
           return a.first > b.first;
        };
        // min stack stores {min_val_could_be_achieved, original value}
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        int cur_max = 0;
        for (const auto num : nums) {
            int min_val_could_be_achieved = num;
            while (min_val_could_be_achieved % 2 == 0) {
                min_val_could_be_achieved /= 2;
            }
            cur_max = max(cur_max, min_val_could_be_achieved);
            pq.push({min_val_could_be_achieved, num});
        }
        
        int diff = INT_MAX;
        while (true) {
            pair<int, int> pa = pq.top();
            pq.pop();
            int min_val = pa.first;
            int val = pa.second;
            //cout<<min_val<<val<<endl;
            diff = min(diff, cur_max - min_val);
            if (min_val % 2 == 0 && min_val >= val) break;
            cur_max = max(cur_max, min_val * 2);
            pq.push({min_val * 2, val});
        }
        
        return diff;
    }
};