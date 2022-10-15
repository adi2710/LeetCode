class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq1(58), freq2(58);
        int cnt1 = 0, cnt2 = 0, n = s.size();
        for(char ch : t){
            freq2[ch - 'A']++;
            if(freq2[ch - 'A'] == 1)
                cnt2++;
        }
        int st = -1, len = 1e6;
        for(int i = 0, j = 0; j < n; )
        {
            while(j < n && cnt1 < cnt2){
                freq1[s[j] - 'A']++;
                if(freq1[s[j] - 'A'] == freq2[s[j] - 'A'])
                    cnt1++;
                j++;
            }
            if(cnt1 == cnt2 && len > j - i)
            {
                st = i;
                len = j - i;
            }
            while(i < j && cnt1 == cnt2)
            {
                freq1[s[i] - 'A']--;
                if(freq1[s[i] - 'A'] < freq2[s[i] - 'A'])
                    cnt1--;
                i++;
            }
            if(st != -1 && len > j - i + 1)
            {
                st = i - 1;
                len = j - i + 1;
            }
        }
        if(st == -1)
            return "";
        return s.substr(st, len);
    }
};