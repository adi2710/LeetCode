class Solution {
public:
    int totalMoney(int n) {
        int full = n / 7, partial = n % 7;
        return 28 * full + full * max(0, full - 1) * 7 / 2 + partial * (2 * (full + 1) + (partial - 1)) / 2;
    }
};