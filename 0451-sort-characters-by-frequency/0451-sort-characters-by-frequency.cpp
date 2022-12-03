class Solution {
public:
    string frequencySort(string s) {
        string ans;
        vector<pair<char, int>> freq(256, {0, 0});
        for (const auto &c : s) {
            freq[c].first = c;
            freq[c].second++;
        }
        sort(freq.begin(), freq.end(), [](pair<char, int>& l, pair<char, int>& r) {
            return l.second > r.second;
        });
        for (auto it = freq.begin(); it != freq.end(); ++it)
            ans.append(it -> second, it -> first);
        return ans;
    } 
};