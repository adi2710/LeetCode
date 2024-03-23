class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++) {
            for(int l = 0; l < arr[i].size(); l++) {
                string sub;
                for(int r = l; r < arr[i].size(); r++) {
                    sub.push_back(arr[i][r]);
                    mp[sub]++;
                }
            }
        }
        
        vector<string> ans(n);
        for(int i = 0; i < n; i++) {
            unordered_map<string, int> tmp;
            for(int l = 0; l < arr[i].size(); l++) {
                string sub;
                for(int r = l; r < arr[i].size(); r++) {
                    sub.push_back(arr[i][r]);
                    tmp[sub]++;
                }
            }
            for(auto &[patt, count] : tmp) {
                if(mp[patt] == count) {
                    if(ans[i].empty())
                        ans[i] = patt;
                    else {
                        if(ans[i].size() > patt.size())
                            ans[i] = patt;
                        else if(ans[i].size() == patt.size())
                            ans[i] = min(ans[i], patt);
                    }
                }
            }
        }
        return ans;
    }
};