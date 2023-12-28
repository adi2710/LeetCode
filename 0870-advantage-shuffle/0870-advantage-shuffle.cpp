class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        for(int x : nums1)
            mp[x]++;
        for(int i = 0; i < nums2.size(); i++) {
            auto it = mp.upper_bound(nums2[i]);
            if(it == mp.end())
                it = mp.begin();
            nums1[i] = (*it).first;
            (*it).second--;
            if((*it).second == 0)
                mp.erase(it);
        }
        return nums1;
    }
};