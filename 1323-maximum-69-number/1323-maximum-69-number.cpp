class Solution {
public:
    int maximum69Number (int num) {
        int pos = 0;
        for(int i = 1; num / i > 0; i *= 10)
        {
            int dig = (num / i) % 10;
            if(dig == 6)
                pos = i;
        }
        num += pos * 3; 
        return num;
    }
};