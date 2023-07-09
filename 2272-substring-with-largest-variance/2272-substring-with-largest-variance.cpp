class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        vector<int> freq(26);
        for(char ch : s)
            freq[ch - 'a']++;
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < 26; j++){
                if(i == j || freq[i] == 0 || freq[j] == 0)
                    continue;
                int cnt1 = 0, cnt2 = 0, rem = freq[j];
                for(char ch : s)
                {
                    if(ch - 'a' == i)
                        cnt1++;
                    else if(ch - 'a' == j)
                        cnt2++, rem--;
                    if(cnt2 > 0)
                        ans = max(ans, cnt1 - cnt2);
                    if(cnt1 < cnt2 && rem > 0)
                        cnt1 = cnt2 = 0;
                }
            }
        }
        return ans;
    }
};