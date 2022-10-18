class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int bit = 0; bit <= 30; bit++)
        {
            int mask = 1 << bit;
            if(c & mask)
            {
                if((a & mask) == 0 && (b & mask) == 0)
                    ans++;
            }
            else if((c & mask) == 0)
            {
                if(a & mask)
                    ans++;
                if(b & mask)
                    ans++;
            }
        }
        return ans;
    }
};