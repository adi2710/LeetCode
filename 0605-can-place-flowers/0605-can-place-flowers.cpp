class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int prev = -1, count = 0;
        for(int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 1) {
                int len = i - prev - 1;
                if(prev > -1)
                    len = max(0, len - 1);
                count += len / 2;
                prev = i;
            }
        }
        if(prev > -1)
            prev++;
        count += (flowerbed.size() - prev) / 2;
        return n <= count;
    }
};