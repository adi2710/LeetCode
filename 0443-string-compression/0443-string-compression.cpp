class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), j = 0;
        for(int i = 0; i < n;)
        {
            char ch = chars[i];
            int cnt = 0;
            while(i < n && ch == chars[i])
                cnt++, i++;
            string num = to_string(cnt);
            chars[j++] = ch;
            if(cnt > 1){
                for(char ch : num)
                    chars[j++] = ch;
            }
        }
        return j;
    }
};